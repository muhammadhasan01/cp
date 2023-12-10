#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int v, h;
    cin >> v >> h;
    vector<vector<int>> grid(v + 1, vector<int>(h + 1));
    int n;
    cin >> n;
    vector<int> v1(n + 1), h1(n + 1), v2(n + 1), h2(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v1[i] >> h1[i] >> v2[i] >> h2[i];
        for (int y = v1[i]; y <= v2[i]; y++) {
            for (int x = h1[i]; x <= h2[i]; x++) {
                grid[y][x] = i;
            }
        }
    }
    vector<vector<long long>> dp(v + 2, vector<long long>(h + 2));
    for (int y = v - 1; y >= 0; y--) {
        for (int x = 1; x <= h; x++) {
            if (grid[y][x] > 0) {
                continue;
            }
            int i = grid[y + 1][x];
            if (i == 0) {
                dp[y][x] = dp[y + 1][x];
                continue;
            }
            int l = h1[i] - 1;
            int r = h2[i] + 1;
            dp[y][x] = 1 + dp[y + 1][l] + dp[y + 1][r];
        }
    }
    long long ans = 0;
    for (int x = 1; x <= h; x++) {
        ans = max(ans, dp[0][x]);
    }
    cout << ans << '\n';
    
    return 0;
}