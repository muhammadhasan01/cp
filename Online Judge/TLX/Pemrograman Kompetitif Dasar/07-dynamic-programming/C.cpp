#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
    }
    cout << dp[n] << '\n';
    
    return 0;
}