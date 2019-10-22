// author : m.hasan01
// inspired from : https://github.com/Sohieeb/2019-icpc-malaysia-national-contest
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int M = 1e9 + 7;
int n, e, k;
bool inv[N][N];
int dp[N][(1<<9)];

int mmod(int a, int b) {
    return ((a % M + b % M) % M + M) % M;
}

int get(int a, int b) {
    a ^= (1 << b);
    return (a << 1 | 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        inv[u][v] = 1;
    }

    dp[1][(1<<(e + 1)) - 1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << (2 * e + 1)); j++) {
            if (dp[i][j]) {
                if (j & (1 << (2 * e))) {
                    if (i - e >= 1 && !inv[i][i - e]) {
                        int ps = get(j, 2 * e);
                        dp[i + 1][ps] = mmod(dp[i + 1][ps], dp[i][j]);
                        continue;
                    }
                }
                for (int k = 0; k < 2 * e; k++) {
                    int pos = i - k + e;
                    if (pos > n || pos < 1) continue;
                    if (inv[i][pos]) continue;
                    if (j & (1 << k)) {
                        int ps = get(j, k);
                        dp[i + 1][ps] = mmod(dp[i + 1][ps], dp[i][j]);
                    }
                }
            }
        }
    }
    cout << dp[n + 1][(1 << (e + 1)) - 1] << '\n';

    return 0;
}
