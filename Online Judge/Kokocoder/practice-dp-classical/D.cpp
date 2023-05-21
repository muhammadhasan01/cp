#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int sum = 1; sum <= n; sum++) {
        for (int dice = 1; dice <= 6; dice++) {
            int sumb = sum - dice;
            if (sumb < 0) {
                break;
            }
            dp[sum] = (dp[sum] + dp[sumb]) % MOD;
        }
    }
    cout << dp[n] << '\n';
    
    return 0;
}