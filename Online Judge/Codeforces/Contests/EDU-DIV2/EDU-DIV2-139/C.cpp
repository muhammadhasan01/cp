#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(K, vector<char>(n));
    int cntB = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'B') {
                cntB++;
            }
        }
    }
    vector<vector<int>> dp(2, vector<int>(2));
    for (int j = 0; j < n; j++) {
        vector<vector<int>> ndp(2, vector<int>(2));
        for (int i = 0; i < K; i++) {
            if (a[i][j] == 'B') {
                ndp[i][0] = 1 + max(dp[i][0], dp[i][1]);
            }
        }
        if (a[0][j] == 'B' && a[1][j] == 'B') {
            ndp[0][1] = 1 + ndp[1][0];
            ndp[1][1] = 1 + ndp[0][0];
        }
        dp.swap(ndp);
    }
    int cur = max({dp[0][0], dp[0][1], dp[1][0], dp[1][1]});
    cout << (cur == cntB ? "YES" : "NO") << '\n';
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