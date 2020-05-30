#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 5e5 + 5;
const int K = 7;

int n, q;
int a[N];
int has[N];
vector<int> p[M];
int dp[(1 << K)], cnt[M];
long long ans;

inline void add(int val, int sign) {
    for (int mask = 0; mask < (1 << p[val].size()); mask++) {
        if (!mask)
            dp[mask] = 1;
        else
            dp[mask] = (dp[mask & (mask - 1)] * p[val][__builtin_ctz(mask)]);
        if (sign < 0)
            cnt[dp[mask]]--;
        if (__builtin_popcount(mask) & 1)
            ans -= cnt[dp[mask]] * sign;
        else
            ans += cnt[dp[mask]] * sign;
        if (sign > 0)
            cnt[dp[mask]]++;
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < M; i++) {
        if (!p[i].empty()) continue;
        for (int j = i; j < M; j += i) {
            p[j].emplace_back(i);
        }
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        has[i] = 1;
    }
    while (q--) {
        int x;
        cin >> x;
        add(a[x], has[x]);
        has[x] *= -1;
        cout << ans << '\n';
    }

    return 0;
}