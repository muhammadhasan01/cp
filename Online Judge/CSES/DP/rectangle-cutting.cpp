#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INF));
    for (int x = 1; x <= a; x++) {
        for (int y = 1; y <= b; y++) {
            if (x == y) {
                dp[x][y] = 0;
            } else {
                for (int z = 1; z < x; z++) {
                    dp[x][y] = min(dp[x][y], 1 + dp[z][y] + dp[x - z][y]);
                }
                for (int z = 1; z < y; z++) {
                    dp[x][y] = min(dp[x][y], 1 + dp[x][z] + dp[x][y - z]);
                }
            }
        }
    }
    cout << dp[a][b] << '\n';
    
    return 0;
}