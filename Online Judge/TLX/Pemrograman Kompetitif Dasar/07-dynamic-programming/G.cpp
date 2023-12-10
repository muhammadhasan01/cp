#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 2; i <= n; i += 2) {
        for (int j = 2; j < i; j += 2) {
            dp[i] += dp[j - 2] * dp[i - j];
        }
        dp[i] += dp[i - 2];
    }
    cout << dp[n] << '\n';
    
    return 0;
}