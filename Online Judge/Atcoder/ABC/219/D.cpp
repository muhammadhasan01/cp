#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 305;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> dp(N, vector<int>(N, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> ndp(N, vector<int>(N, INF));
        for (int j = 0; j <= x; j++) {
            for (int k = 0; k <= y; k++) {
                ndp[j][k] = dp[j][k];
                int cj = max(0, j - a[i]);
                int ck = max(0, k - b[i]);
                if (cj >= 0 && ck >= 0) {
                    ndp[j][k] = min(ndp[j][k], dp[cj][ck] + 1);
                }
            }
        }
        for (int j = x; j >= 0; j--) {
            for (int k = y; k >= 0; k--) {
                ndp[j][k] = min(ndp[j][k], ndp[j + 1][k]);
                ndp[j][k] = min(ndp[j][k], ndp[j][k + 1]);
            }
        }
        dp.swap(ndp);
    }
    int ans = dp[x][y];
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
    
    return 0;
}