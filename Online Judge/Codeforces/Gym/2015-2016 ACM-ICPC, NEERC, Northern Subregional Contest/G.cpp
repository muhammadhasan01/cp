#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace(v);
        deg[v]++;
    }
    

    return 0;
}