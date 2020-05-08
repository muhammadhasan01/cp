#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 1e6 + 5;

long long n, m, p;
int len;
int a[N], b[N], ans[N];
int cnt[M];
int req[M];
set<int> s;
unordered_map<int, int> mp;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }
    int ord = 0;
    for (auto& e : s) {
        mp[e] = ++ord;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
    }
    int sz = 0;
    for (int i = 1; i <= m; i++) {
        b[i] = mp[b[i]];
        if (++req[b[i]] == 1) sz++;
    }
    for (int i = 1; i <= p; i++) {
        int last = -1;
        int cursz = 0;
        for (int j = i; j <= n; j += p) {
            if ((1LL) * j + (1LL) * (m - 1) * p > n) break;
            if (last == -1) {
                for (int k = 0; k < m; k++) {
                    int cur = a[j + k * p];
                    if (cnt[cur] + 1 == req[cur]) {
                        cursz++;
                    } else if (cnt[cur] == req[cur] && req[cur] > 0) {
                        cursz--;
                    }
                    ++cnt[cur];
                }
            } else {
                int bfr = a[j - p];
                int now = a[j + (m - 1) * p];
                if (cnt[bfr] - 1 == req[bfr] && req[bfr] > 0) {
                    ++cursz;
                } else if (cnt[bfr] == req[bfr] && req[bfr] > 0) {
                    --cursz;
                }
                cnt[bfr]--;
                if (cnt[now] + 1 == req[now]) {
                    ++cursz;
                } else if (cnt[now] == req[now] && req[now] > 0) {
                    --cursz;
                }
                cnt[now]++;
            }
            if (cursz == sz) ans[++len] = j;
            last = j;
        }
        if (last == -1) continue;
        for (int k = 0; k < m; k++) {
            int cur = a[last + k * p];
            cnt[cur]--;
        }
    }
    sort(ans + 1, ans + 1 + len);
    cout << len << '\n';
    for (int i = 1; i <= len; i++) {
        cout << ans[i] << (i == len ? '\n' : ' ');
    }

    return 0;
}