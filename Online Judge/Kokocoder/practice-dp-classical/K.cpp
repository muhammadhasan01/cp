#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int coin : coins) {
        for (int sum = coin; sum <= x; sum++) {
            int sumb = sum - coin;
            dp[sum] = (dp[sum] + dp[sumb]) % MOD;
        }
    }
    cout << dp[x] << '\n';
    
    return 0;
}