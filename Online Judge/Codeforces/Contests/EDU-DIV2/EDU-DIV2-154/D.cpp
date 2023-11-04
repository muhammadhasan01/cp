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
    vector<vector<int>> dp(n + 1, vector<int>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 1;
    dp[1][1] = 0;
    int posG = 1, posS = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] >= a[i]) {
            posS = i;
        }
        if (a[i - 1] <= a[i]) {
            posG = i;
        }
        dp[i][1] = min(dp[posS - 1][0], dp[posS - 1][1] + 1);
        dp[i][0] = dp[posG - 1][0] + 1;
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
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