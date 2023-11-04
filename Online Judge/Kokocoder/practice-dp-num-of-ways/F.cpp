#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(m + 1, vector<int>(b + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<vector<int>> ndp(m + 1, vector<int>(b + 1));
        for (int line = 0; line <= m; line++) {
            for (int bug = 0; bug <= b; bug++) {
                ndp[line][bug] = dp[line][bug];
                if (line - 1 >= 0 && bug - a[i] >= 0) {
                    ndp[line][bug] = (ndp[line][bug] + ndp[line - 1][bug - a[i]]) % mod;
                }
            }
        }
        dp.swap(ndp);
    }
    int ans = 0;
    for (int bug = 0; bug <= b; bug++) {
        ans = (ans + dp[m][bug]) % mod;
    }
    cout << ans << '\n';
    
    return 0;
}