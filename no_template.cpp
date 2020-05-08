#include <bits/stdc++.h>

using namespace std;



int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 5, W = 10;
    vector<int> w = {0, 5, 4, 3, 6, 13};
    vector<int> v = {0, 10, 40, 30, 50, 70};
    int dp[n + 10][W + 10];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j];
                if (w[i] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
                }
            }
            cout << dp[i][j] << " ";
        }cout << '\n';
    }

    return 0;
}