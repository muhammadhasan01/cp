#include <bits/stdc++.h>

using namespace std;

const int K = 2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp;
    for (int len = 1; len <= n; len++) {
        vector<vector<int>> ndp(n - len + 1, vector<int>(K));
        for (int l = 0; l < n; l++) {
            int r = l + len - 1;
            if (r >= n) {
                break;
            }
            if (len == 1) {
                ndp[l][0] = ndp[l][1] = 0;
            } else if (len == 2) {
                ndp[l][0] = ndp[l][1] = (a[l] != a[r]);
            } else {
                ndp[l][0] = min((a[l] != a[l + 1]) + dp[l + 1][0], (a[l] != a[r]) + dp[l + 1][1]);
                ndp[l][1] = min((a[r] != a[r - 1]) + dp[l][1], (a[r] != a[l]) + dp[l][0]);
            }
        }
        dp.swap(ndp);
    }
    cout << min(dp[0][0], dp[0][1]) << '\n';
    
    return 0;
}