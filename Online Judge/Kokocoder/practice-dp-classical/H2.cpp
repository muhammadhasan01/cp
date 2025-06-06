#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    vector<int> dp(3);
    for (int i = 0; i < n; i++) {
        vector<int> ndp(3);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) {
                    continue;
                }
                ndp[j] = max(ndp[j], v[i][j] + dp[k]);
            }
        }
        dp.swap(ndp);
    }
    int ans = 0;
    for (int j = 0; j < 3; j++) {
        ans = max(ans, dp[j]);
    }
    cout << ans << '\n';

    return 0;
}