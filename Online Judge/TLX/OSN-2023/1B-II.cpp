#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rgt(n + 1, vector<int>(2, n + 1));
    vector<vector<int>> lft(n + 1, vector<int>(2, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);           
        }
        if (v < rgt[u][0]) {
            rgt[u][1] = rgt[u][0];
            rgt[u][0] = v;
        } else if (v < rgt[u][1]) {
            rgt[u][1] = v;
        }
        if (u > lft[v][0]) {
            lft[v][1] = lft[v][0];
            lft[v][0] = u;
        } else if (u > lft[v][1]) {
            lft[v][1] = u;
        }
    }
    long long ans = 0;
    for (int u = 1; u <= n; u++) {
        // compute lonely exactly 1
        ans += 1LL * (u - lft[u][0]) * (rgt[u][0] - u);
        // compute lonely exactly 2
        int v = rgt[u][0];
        if (v <= n && lft[v][0] == u) {
            ans += 2LL * (u - max(lft[u][0], lft[v][1])) * (min(rgt[v][0], rgt[u][1]) - v);
        }
    }
    cout << ans << '\n';
    
    return 0;
}