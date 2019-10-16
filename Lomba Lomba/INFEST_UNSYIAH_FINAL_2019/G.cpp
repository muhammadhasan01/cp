#include <bits/stdc++.h>
using namespace std;

int n;
int m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<int> g(n + 3, 0);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        g[u + 1]++;
        g[v + 1]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) if (g[i] == 0) ans++;
    cout << ans << '\n';

    return 0;
}
