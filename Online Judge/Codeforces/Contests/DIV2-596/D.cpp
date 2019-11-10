#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n, k;
int p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    p[1] = 1;
    for (int i = 2; i <= N - 5; i++) {
        if (p[i] == 0) {
            for (int j = i; j <= N - 5; j += i) {
                p[j] = i;
            }
        }
    }
    cin >> n >> k;
    ll ans = 0;
    map<vector<pair<int,int>>, int> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int cnt = 0;
        vector<pair<int,int>> cur, ruc;
        int pr;
        while (x != 1) {
            pr = p[x];
            int af = x / pr;
            cnt++;
            x = af;
            if (pr == p[af]) continue;
            if (cnt % k == 0) {
                cnt = 0;
            } else {
                int cpr = cnt % k;
                cur.push_back({pr, cpr});
                ruc.push_back({pr, k - cpr});
                cnt = 0;
            }
        }

        if (cnt % k != 0) {
            int cpr = cnt % k;
            cur.push_back({pr, cpr});
            ruc.push_back({pr, k - cpr});
        }
        ans += (1LL) * m[ruc];
        m[cur]++;
    }
    cout << ans << '\n';

    return 0;
}
