#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const int INF = 1e9 + 20;

int n, B;
int par[N], sz[N];
int dp[N][N][2]; // (node, size, no-coupon/coupon)
int a[N][2];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> B;
    cin >> a[1][0] >> a[1][1];
    a[1][1] = a[1][0] - a[1][1];
    sz[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> par[i];
        a[i][1] = a[i][0] - a[i][1];
        sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0][0] = 0;
        dp[i][1][0] = a[i][0];
        dp[i][0][1] = INF;
        dp[i][1][1] = a[i][1];
        for (int j = 2; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    for (int u = n; u >= 2; u--) {
        int v = par[u];
        for (int it = 0; it <= sz[u]; it++) {
            dp[u][it][1] = min(dp[u][it][1], dp[u][it][0]);
        }
        for (int i = sz[v]; i >= 0; i--) {
            for (int j = sz[u]; j >= 0; j--) {
                for (int k = 0; k < 2; k++) {
                    dp[v][i + j][k] = min(dp[v][i + j][k], min(INF, dp[v][i][k] + dp[u][j][k]));
                }
            }
        }
        sz[v] += sz[u];
    }
    int ans = 0;
    for (int i = 0; i <= sz[1]; i++) {
        dp[1][i][1] = min(dp[1][i][1], dp[1][i][0]);
        if (dp[1][i][1] <= B) ans = i;
    }
    cout << ans << '\n';

    return 0;
}