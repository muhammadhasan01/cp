#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 3e3 + 5;
const int K = 3e3 + 5;
const int C = 3;

int dp[N][K][C];
int preH[N][K][C];
int preD[N][K][C];

void add(int& x, int y) {
    x = ((x + y) % MOD + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        if (cc == 'A') {
            s[i] = 0;
        } else if (cc == 'B') {
            s[i] = 1;
        } else if (cc == '?') {
            s[i] = -1;
        }
    }
    dp[0][0][0] = dp[0][0][1] = 1;
    preH[0][0][0] = preH[0][0][1] = 1;
    preD[0][0][0] = preD[0][0][1] = 1;
    vector<int> last(C);
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= k; x++) {
            for (int cc : {0, 1}) {
                if (s[i] != -1 && s[i] != cc) {
                    continue;
                }
                int oc = (cc ^ 1);
                int lst = last[oc];
                if (i - m < lst) {
                    add(dp[i][x][cc], preH[i - 1][x][oc]);
                    if (lst - 1 >= 0) {
                        add(dp[i][x][cc], -preH[lst - 1][x][oc]);
                    }
                } else {
                    add(dp[i][x][cc], preH[i - 1][x][oc]);
                    if (i - m >= 0) {
                        add(dp[i][x][cc], -preH[i - m][x][oc]);
                        if (x - 1 >= 0) {
                            add(dp[i][x][cc], preD[i - m][x - 1][oc]);
                            int plus = i - m - lst + 1;
                            int nx = x - plus;
                            if (lst - 1 >= 0 && nx - 1 >= 0) {
                                add(dp[i][x][cc], -preD[lst - 1][nx - 1][oc]);
                            }
                        }
                    }
                }
            }
        }
        for (int x = 0; x <= k; x++) {
            for (int cc : {0, 1}) {
                add(preH[i][x][cc], dp[i][x][cc]);
                add(preH[i][x][cc], preH[i - 1][x][cc]);
                add(preD[i][x][cc], dp[i][x][cc]);
                if (x - 1 >= 0) {
                    add(preD[i][x][cc], preD[i - 1][x - 1][cc]);
                }
            }
        }
        if (s[i] != -1) {
            last[s[i]] = i;
        }
    }
    int ans = 0;
    add(ans, dp[n][k][0]);
    add(ans, dp[n][k][1]);
    cout << ans << '\n';
    
    return 0;
}