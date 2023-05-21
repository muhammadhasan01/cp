#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
    }
    string res = "";
    int x = n, y = m;
    while (x > 0 && y > 0) {
        if (s[x - 1] == t[y - 1]) {
            res += s[x - 1];
            x--, y--;
        } else if (dp[x][y] == dp[x][y - 1]) {
            y--;
        } else {
            x--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';

    return 0;
}