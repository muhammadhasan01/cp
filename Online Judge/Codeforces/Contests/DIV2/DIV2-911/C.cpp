#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<char> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<int> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, INF));

    function<void(int)> dfs = [&](int u) {
        if (L[u] == 0 && R[u] == 0) {
            dp[u][0] = dp[u][1] = 0;
            return;
        }
        if (L[u] > 0) {
            dfs(L[u]);
            dp[u][0] = min(dp[u][0], (s[u] != 'L') + min(dp[L[u]][0], dp[L[u]][1]));
        }
        if (R[u] > 0) {
            dfs(R[u]);
            dp[u][1] = min(dp[u][1], (s[u] != 'R') + min(dp[R[u]][0], dp[R[u]][1]));
        }
    };

    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << '\n';
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