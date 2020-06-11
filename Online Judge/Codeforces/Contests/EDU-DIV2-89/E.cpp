#include <bits/stdc++.h>

using namespace std;

const long long M = 998244353;
const int N = 2e5 + 5;
const int K = 19;
const int NMax = (1 << K);

int n, m;
int a[N], b[N];
int sp[NMax][K];
int pre[NMax];
long long dp[N];
long long t[4 * N];

void dismiss() {
    cout << 0 << "\n";
    exit(0);
}

int getz(int l, int r) {
    int k = pre[r - l + 1];
    return min(sp[l][k], sp[r - (1 << k) + 1][k]);
}

void update(int v, int s, int e, int pos, long long val) {
    if (s == e && s == pos) {
        t[v] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid) {
        update(v << 1, s, mid, pos, val);
    } else {
        update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = (t[v << 1] + t[v << 1 | 1]) % M;
}

int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r) return 0;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, r);
    int p2 = get(v << 1 | 1, mid + 1, e, l, r);
    return (p1 + p2) % M;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int mini = 2e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mini = min(mini, a[i]);
    }
    unordered_map<int, bool> mp;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        mp[b[i]] = 1;
    }
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] < b[1]) dismiss();
        if (a[i] < b[m] && cur > m) dismiss();
        if (a[i] == b[cur] && cur < m) cur++;
    }
    if (cur < m) dismiss();
    for (int i = 2; i < NMax; i++) {
        pre[i] = 1 + pre[i >> 1];
    }
    for (int i = 1; i <= n; i++) {
        sp[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
    dp[0] = 1;
    update(1, 0, n, 0, dp[0]);
    for (int i = 1; i <= n; i++) {
        if (mp[a[i]] == 0) {
            dp[i] = (i > 1 ? dp[i - 1] : 0);
        } else {
            int l = 1, r = i, pos = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (getz(mid, i) == a[i]) {
                    r = mid - 1;
                    pos = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (pos == -1) continue;
            cerr << i << " => " << pos << '\n';
            dp[i] = get(1, 0, n, pos - 1, i - 1);
        }
        cerr << i << " ==> " << dp[i] << '\n';
        update(1, 0, n, i, dp[i]);
    }
    cout << dp[n] << '\n';
    
    return 0;
}