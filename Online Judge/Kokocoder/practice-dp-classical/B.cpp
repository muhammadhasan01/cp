#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    cin >> n >> w;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(w + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
            }
        }
    }
    cout << dp[n - 1][w] << '\n';

    return 0;
}