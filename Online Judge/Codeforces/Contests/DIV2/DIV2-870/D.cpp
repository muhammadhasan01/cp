#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(K, -INF);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        vector<int> ndp(K, -INF);
        ndp[0] = max(dp[0], b + i);
        ndp[1] = max(dp[1], dp[0] + b);
        ans = max(ans, dp[1] + b - i);
        dp.swap(ndp);
    }
    cout << ans << '\n';
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