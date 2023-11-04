#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    if (n == 1) {
        cout << 2LL * abs(a[1] - b[1]) << '\n';
        return;
    }
    //  bl - ar - br + al => -ar - br + al + bl
    // -bl + ar + br - al =>  ar + br - al - bl
    //  bl - ar + br - al => -ar + br - al + b1
    // -bl + ar - br + al =>  ar - br + al - b1
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
    vector<vector<long long>> mx(n + 1, vector<long long>(4, -INF));
    dp[0][0] = 0;
    mx[0][0] = dp[0][0] + a[1] + b[1];
    mx[0][1] = dp[0][0] - a[1] - b[1];
    mx[0][2] = dp[0][0] - a[1] + b[1];
    mx[0][3] = dp[0][0] + a[1] - b[1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            int d = i - j;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], -a[i] - b[i] + mx[d][0]);
            dp[i][j] = max(dp[i][j],  a[i] + b[i] + mx[d][1]);
            dp[i][j] = max(dp[i][j], -a[i] + b[i] + mx[d][2]);
            dp[i][j] = max(dp[i][j],  a[i] - b[i] + mx[d][3]);
            if (i + 1 <= n) {
                mx[d][0] = max(mx[d][0], dp[i][j] + a[i + 1] + b[i + 1]);
                mx[d][1] = max(mx[d][1], dp[i][j] - a[i + 1] - b[i + 1]);
                mx[d][2] = max(mx[d][2], dp[i][j] - a[i + 1] + b[i + 1]);
                mx[d][3] = max(mx[d][3], dp[i][j] + a[i + 1] - b[i + 1]);
            }
        }
    }
    cout << dp[n][k] << '\n';
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