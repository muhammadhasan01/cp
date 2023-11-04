#include <bits/stdc++.h>

using namespace std;

const int D = 5000;
const int B = 2500;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string ss;
    cin >> ss;
    int n;
    cin >> n;
    vector<int> x(n);
    vector<bool> vis(D + 5);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] += B;
        vis[x[i]] = true;
    }
    int ans = INT_MAX;
    for (int d = 1; d <= D; d++) {
        vector<int> dp(D + 1);
        for (int i = 0; i <= D; i++) {
            int j = i - d;
            dp[i] = (vis[i] ? n - 1 : n + 1);
            if (j >= 0) {
                dp[i] = min(dp[i], dp[j] + (vis[i] ? -1 : 1));
            }
            ans = min(ans, dp[i]);
        }
    }
    cout << ans << '\n';
    
    return 0;
}