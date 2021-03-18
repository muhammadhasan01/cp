#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 205;
const int K = 1005;
const int mod = 1e9 + 7;
 
int n, m;
int a[N], dp[2][N][K];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    dp[1][0][0] = dp[1][1][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= m; k++) {
                int t = k + j * (a[i] - a[i - 1]);
                if (m < t)
                    continue;
                dp[i % 2][j][t] = (dp[i % 2][j][t] + 1LL * (j + 1) * dp[1 - i % 2][j][k]) % mod;
                dp[i % 2][j + 1][t] = (dp[i % 2][j + 1][t] + dp[1 - i % 2][j][k]) % mod;
                if (j)
                    dp[i % 2][j - 1][t] = (dp[i % 2][j - 1][t] + 1LL * j * dp[1 - i % 2][j][k]) % mod;
            }
        }
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= m; k++)
                dp[1 - i % 2][j][k] = 0;
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        ans = (ans + dp[n % 2][0][i]) % mod;
    cout << ans << '\n';
    
    return 0;
}