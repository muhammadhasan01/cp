#include <bits/stdc++.h>

using namespace std;

const int N = 19;

int n;
long long m;
long long g[N][N];
long long dp[(1 << N)][N];
long long ans;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = true;
        if (u > v) swap(u, v);
        dp[((1 << u) | (1 << v))][v]++;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        int last = -1;
        for (int i = 0; i < n; i++) {
            bool b = (mask & (1 << i));
            if (!b) continue;
            if (last == -1) {
                last = i;
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (!g[i][j]) continue;
                if (!bool(mask & (1 << j))) continue;
                dp[mask][i] += dp[(mask ^ (1 << i))][j];
            }
            if (g[i][last]) {
                ans += dp[mask][i];
            }
        }
    }
    cout << (ans - m) / 2 << '\n';

    return 0;
}