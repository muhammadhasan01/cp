#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

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
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int c : coins) {
        for (int sum = c; sum <= x; sum++) {
            dp[sum] = min(dp[sum], 1 + dp[sum - c]);
        }
    }
    int ans = dp[x];
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}