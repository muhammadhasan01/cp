#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, k;
    long long x;
    cin >> n >> k >> x;
    vector<long long> a(n + 1);
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
    }

    auto getVal = [&](int pos, int cnt) -> long long {
        return pre[pos] + x * cnt - x * (pos - cnt);
    };

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0], getVal(i, 0));
        for (int j = 1; j <= min(i, k); j++) {
            long long val = getVal(i, j);
            dp[i][j] = min({dp[i][j], dp[i - 1][j - 1], dp[i - 1][j], val});
        }
    }

    long long ans = -LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        int len = n - i;
        for (int take = k; take >= 0; take--) {
            if (take > i) {
                continue;
            }
            if (k - take > len) {
                continue;
            }
            long long val = getVal(i, take);
            for (int j = take, pos = i; j >= 0 && pos >= 1; j--, pos--) {
                long long cur = val - dp[pos][j];
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}