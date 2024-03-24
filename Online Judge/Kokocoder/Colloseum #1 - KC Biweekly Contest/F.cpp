#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 105;
const int A = 26;

int dp[N][N][A][A];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        char cc;
        cin >> cc;
        s[i] = cc - 'a';
    }
    for (int l = 0; l < n; l++) {
        for (int r = 0; r < n; r++) {
            for (int x = 0; x < A; x++) {
                for (int y = 0; y < A; y++) {
                    dp[l][r][x][y] = INF;
                }
            }
        }
    }
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n; l++) {
            int r = l + len - 1;
            if (r >= n) {
                break;
            }
            if (len == 1) {
                dp[l][r][s[l]][s[l]] = 1;
                continue;
            }
            for (int m = l; m < r; m++) {
                vector<int> miniL(A, INF);
                for (int xl = 0; xl < A; xl++) {
                    for (int yl = 0; yl < A; yl++) {
                        miniL[xl] = min(miniL[xl], dp[l][m][xl][yl]);
                    }
                }
                vector<int> miniR(A, INF);
                for (int xr = 0; xr < A; xr++) {
                    for (int yr = 0; yr < A; yr++) {
                        miniR[yr] = min(miniR[yr], dp[m + 1][r][xr][yr]);
                    }
                }
                for (int xl = 0; xl < A; xl++) {
                    for (int yr = 0; yr < A; yr++) {
                        dp[l][r][xl][yr] = min(dp[l][r][xl][yr], miniL[xl] + miniR[yr]);
                    }
                }
                for (int xl = 0; xl < A; xl++) {
                    for (int yl = 0; yl < A; yl++) {
                        if (dp[l][m][xl][yl] == INF) {
                            continue;
                        }
                        for (int yr = 0; yr < A; yr++) {
                            if (yl + 1 < A && dp[m + 1][r][yl + 1][yr] != INF) {
                                int cur = dp[l][m][xl][yl] + dp[m + 1][r][yl + 1][yr] - 1;
                                if (dp[m + 1][r][yl + 1][yr] == 1) {
                                    dp[l][r][xl][yl] = min(dp[l][r][xl][yl], cur);
                                } else {
                                    dp[l][r][xl][yr] = min(dp[l][r][xl][yr], cur);
                                }
                            }
                            if (yl - 1 >= 0 && dp[m + 1][r][yl - 1][yr] != INF) {
                                int cur = dp[l][m][xl][yl] + dp[m + 1][r][yl - 1][yr] - 1;
                                if (dp[l][m][xl][yl] == 1) {
                                    dp[l][r][yl - 1][yr] = min(dp[l][r][yl - 1][yr], cur);
                                } else {
                                    dp[l][r][xl][yr] = min(dp[l][r][xl][yr], cur);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int x = 0; x < A; x++) {
        for (int y = 0; y < A; y++) {
            ans = max(ans, n - dp[0][n - 1][x][y]);
        }
    }
    cout << ans << '\n';
    
    return 0;
}