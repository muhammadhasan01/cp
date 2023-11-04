#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e8;
const int N1 = 205;
const int N2 = 205;
const int K1 = 15;
const int K2 = 15;

int k1, k2;
int dp[N1][N2][K1][K2];

int DP(int n1, int n2, int x, int y) {
    if (dp[n1][n2][x][y] != -1) {
        return dp[n1][n2][x][y];
    }
    if (n1 == 0 && n2 == 0) {
        return dp[n1][n2][x][y] = 1;
    }
    int ans = 0;
    if (n1 > 0 && x > 0) {
        ans = (ans + DP(n1 - 1, n2, x - 1, k2)) % MOD;
    }
    if (n2 > 0 && y > 0) {
        ans = (ans + DP(n1, n2 - 1, k1, y - 1)) % MOD;
    }
    return dp[n1][n2][x][y] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    cout << DP(n1, n2, k1, k2) << '\n';
    
    return 0;
}