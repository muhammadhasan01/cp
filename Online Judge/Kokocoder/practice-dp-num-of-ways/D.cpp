 #include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h + 1, vector<char>(w + 1));
    vector<vector<int>> dp(h + 1, vector<int>(w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == '#') {
                continue;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[h][w] << '\n';

    return 0;
}