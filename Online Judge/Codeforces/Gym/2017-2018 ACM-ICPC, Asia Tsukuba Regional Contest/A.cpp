#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, k;
    cin >> l >> k;
    vector<vector<long long>> dp(l + 2, vector<long long>(k + 2, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= l; i++) {
        // try black
        for (int x : {1, k}) {
            if (i - x < 0) {
                continue;
            }
            dp[i][0] += dp[i - x][1];
        }
        dp[i][1] += dp[i - 1][0];
    }
    long long ans = 0;
    for (int i = 1; i <= l; i++) {
        ans += dp[i][0];
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}