#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 1e6 + 5;
const int K = 3;

int n;
int a, b;
int p[N];
long long dp[N][K]; // (pos, not-started/started/finished)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    set<int> primes;
    for (int x : {p[1], p[1] - 1, p[1] + 1, p[n], p[n] - 1, p[n] + 1}) {
        if (x < 0) continue;
        if (x == 0) continue;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                while (x % i == 0) {
                    x /= i;
                }
                primes.emplace(i);
            }
        }
        if (x > 1) {
            primes.emplace(x);
        }
    }
    long long ans = INF;
    for (int pr : primes) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < K; j++) {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < K; j++) {
                if (j == 0) {
                    if (dp[i - 1][0] != INF) {
                        if (p[i] % pr == 0) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][0]);
                        } else if ((p[i] + 1) % pr == 0) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][0] + b);
                        } else if (p[i] > 0 && (p[i] - 1) % pr == 0) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][0] + b);
                        }
                    }
                } else if (j == 1) {
                    if (dp[i - 1][0] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][0] + a);
                    }
                    if (dp[i - 1][1] != INF) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][1] + a);
                    }
                } else if (j == 2) {
                    for (int k = 0; k < K; k++) {
                        if (k == 0) continue;
                        if (dp[i - 1][k] != INF) {
                            if (p[i] % pr == 0) {
                                dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                            } else if ((p[i] + 1) % pr == 0) {
                                dp[i][j] = min(dp[i][j], dp[i - 1][k] + b);
                            } else if (p[i] > 0 && (p[i] - 1) % pr == 0) {
                                dp[i][j] = min(dp[i][j], dp[i - 1][k] + b);
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < K; j++) {
            ans = min(ans, dp[n][j]);
        }
    }
    cout << ans << '\n';

    return 0;
}