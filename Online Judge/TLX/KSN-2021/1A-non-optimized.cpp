#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 3e3 + 5;
const int K = 3e3 + 5;
const int C = 3;

int dp[N][K][C];

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
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= k; x++) {
            for (int cc : {0, 1}) {
                if (s[i] != -1 && s[i] != cc) {
                    continue;
                }
                int oc = (cc ^ 1);
                for (int j = i - 1; j >= 0; j--) {
                    if (s[j + 1] == oc) {
                        break;
                    }
                    int len = i - j;
                    if (len < m) {
                        add(dp[i][x][cc], dp[j][x][oc]);
                    } else {
                        int plus = len - m + 1;
                        int nx = x - plus;
                        if (nx < 0) {
                            break;
                        }
                        add(dp[i][x][cc], dp[j][nx][oc]);
                    }
                }
            }
        }
    }
    int ans = 0;
    add(ans, dp[n][k][0]);
    add(ans, dp[n][k][1]);
    cout << ans << '\n';
    
    return 0;
}