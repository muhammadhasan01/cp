#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int M = 20;
int n, m, k;
long long a[M], dp[N][M], c[M][M], pre[M];

int bits(long long k) {
    int ret = 0;
    while (k > 0) {
        if (k & 1) ret++;
        k /= 2;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        int u, v, q;
        cin >> u >> v >> q;
        c[u][v] = q;
    }

    pre[0] = 1;
    for (int i = 1; i <= n; i++) {
        pre[i] = 2 * pre[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        dp[pre[i - 1]][i] = a[i];
    }
    for (long long mask = 0; mask < pre[n]; mask++) {
        for (int i = 1; i <= n; i++) {
            if (mask & pre[i - 1]) {
                for (int j = 1; j <= n; j++) {
                    if ((mask & pre[j - 1]) == 0) {
                        dp[mask | pre[j - 1]][j] = max(dp[mask | pre[j - 1]][j], dp[mask][i] + c[i][j] + a[j]);
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (long long mask = 0; mask < pre[n]; mask++) {
        if (bits(mask) == m) {
            for (int i = 1; i <= n; i++) {
                ans = max(ans, dp[mask][i]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
