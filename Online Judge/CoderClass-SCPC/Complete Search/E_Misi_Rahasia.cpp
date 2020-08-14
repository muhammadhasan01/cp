#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int n, m;
bool ok[N][N];
bool dp[(1 << N)];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ok[u][v] = ok[v][u] = 1;
    }
    int ans = 0; dp[0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            bool b = (mask & (1 << i));
            if (!b) continue;
            int before_mask = (mask ^ (1 << i));
            if (!dp[before_mask]) break;
            bool flag = true;
            for (int j = i + 1; j < n; j++) {
                bool on = (mask & (1 << j));
                if (!on) continue;
                if (!ok[i][j]) {
                    flag = false;
                    break;
                }
            }
            dp[mask] = flag;
            break;
        }
        if (dp[mask]) ans = max(ans, __builtin_popcount(mask));
    }
    cout << ans << '\n';

    return 0;
}