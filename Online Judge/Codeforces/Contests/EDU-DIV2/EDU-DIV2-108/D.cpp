#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    long long maks = 0;
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if (j > n) {
                break;
            }
            if (len == 1) {
                dp[i][j] = 0;
            } else if (len == 2) {
                dp[i][j] = a[i] * b[j] + a[j] * b[i] - a[i] * b[i] - a[j] * b[j];
            } else {
                dp[i][j] = a[i] * b[j] + a[j] * b[i] - a[i] * b[i] - a[j] * b[j] + dp[i + 1][j - 1];
            }
            maks = max(maks, dp[i][j]);
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += a[i] * b[i];
    }
    long long ans = res + maks;
    cout << ans << '\n';
    
    return 0;
}