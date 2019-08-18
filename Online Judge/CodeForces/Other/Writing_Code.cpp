#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500 + 5;
int n, b, m;
int a[N];
ll mod, dp[3][N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> b >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int it = 1; it <= n; it++) {
        int i = it & 1;
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= b; k++) {
                if (it == 1) {
                    dp[i][j][k] = (j * a[it] == k ? 1 : 0);
                } else {
                    dp[i][j][k] = dp[i ^ 1][j][k];
                    if (j > 0 && k >= a[it]) {
                        dp[i][j][k] += dp[i][j - 1][k - a[it]];
                        dp[i][j][k] %= mod;
                    }
                    dp[i][j][k] %= mod;
                }
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k <= b; k++) {
        ans += dp[n & 1][m][k];
        ans %= mod;
    }
    cout << (ans % mod + mod) % mod << '\n';

    return 0;
}
