#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> mex(n + 1, vector<int>(n + 1));
    for (int l = 1; l <= n; l++) {
        vector<int> mp(n + 1);
        int cur = 0;
        for (int r = l; r <= n; r++) {
            mp[a[r]]++;
            while (mp[cur] > 0) {
                cur++;
            }
            mex[l][r] = cur;
        }
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
    dp[0][0] = true;
    for (int r = 1; r <= n; r++) {
        dp[r] = dp[r - 1];
        for (int l = 1; l <= r; l++) {
            if (l == r || (mex[l][r] != mex[l + 1][r] && mex[l][r] != mex[l][r - 1])) {
                int cur = mex[l][r];
                for (int val = 0; val <= n; val++) {
                    if (dp[l - 1][val]) {
                        dp[r][(val ^ cur)] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int val = 0; val <= n; val++) {
        if (dp[n][val]) {
            ans = val;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}