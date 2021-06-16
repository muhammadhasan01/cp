#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF)), go(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int mini = INF, maxi = -INF;
            for (int k = i; k >= j; k--) {
                mini = min(mini, a[k]);
                maxi = max(maxi, a[k]);
                int cur = dp[k - 1][j - 1] + maxi - mini;
                if (cur < dp[i][j]) {
                    dp[i][j] = cur;
                    go[i][j] = k - 1;
                }
            }
        }
    }
    int i = n, ;
    while (it_i > 0) {
        int j = go[i][] 
    }

    return 0;
}