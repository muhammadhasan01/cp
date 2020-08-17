#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[2] = 1, dp[3] = 1, dp[4] = 1;
    for (int i = 5; i <= n; i++) {
        dp[i] = INF;
        for (int j = 2; j <= i; j++) {
            dp[i] = min(dp[i], dp[j - 2] + 1 + dp[i - (j + 1) + 1]);
        }
        cerr << i << " => " << dp[i] << '\n';
    }

    return 0;
}