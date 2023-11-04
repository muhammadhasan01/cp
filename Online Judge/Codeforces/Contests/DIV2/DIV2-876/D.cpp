#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    dp[1][0] = n;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] < a[i] && dp[k][i - 1] != INF) {
                dp[k][i] = min(dp[k][i], dp[k][i - 1] - 1);
            }
            int kb = k;
            for (int j = i + 1; j <= n; j++) {
                if (a[j - 1] > a[j]) {
                    kb = k - 1;
                    break;
                }
            }
            for (int j = 0; j <= i - 2; j++) {
                if (a[j] < a[i] && dp[kb][j] != INF) {
                    dp[k][i] = min(dp[k][i], dp[kb][j] - 1);
                }
            }
        }
    }
    int ans = INF;
    for (int k = 1; k <= n; k++) {
        ans = min(ans, *min_element(dp[k].begin(), dp[k].end()));
        cout << ans << " \n"[k == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}