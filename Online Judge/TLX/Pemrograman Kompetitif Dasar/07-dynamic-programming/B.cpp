#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    vector<vector<pair<int, int>>> par(k + 1, vector<pair<int, int>>(n + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        int w, h;
        cin >> w >> h;
        for (int x = 0; x <= n; x++) {
            if (dp[i - 1][x] != -1) {
                dp[i][x] = dp[i - 1][x];
                par[i][x] = {i - 1, x};
            }
            if (x - w >= 0 && dp[i - 1][x - w] != -1 && dp[i - 1][x - w] + h > dp[i][x]) {
                dp[i][x] = dp[i - 1][x - w] + h;
                par[i][x] = {i - 1, x - w};
            }
        }
    }
    int ans = 0;
    for (int x = 0; x <= n; x++) {
        ans = max(ans, dp[k][x]);
    }
    int w = -1;
    for (int x = 0; x <= n; x++) {
        if (ans == dp[k][x]) {
            w = x;
            break;
        }
    }
    assert(w != -1);
    vector<int> track;
    int i = k;
    while (i >= 1) {
        auto [j, wb] = par[i][w];
        if (wb < w) {
            track.emplace_back(i);
        }
        i = j, w = wb;
    }
    reverse(track.begin(), track.end());
    for (int x : track) {
        cout << x << '\n';
    }
    
    return 0;
}