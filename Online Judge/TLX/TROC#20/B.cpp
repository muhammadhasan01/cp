#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m;
set<int> st[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        st[u].emplace(v);
        st[v].emplace(u);
    }
    int ans = 0;
    for (int d = 1; d < n; d++) {
        for (int u = 0; u < n; u++) {
            int v = (u + d) % n;
            if (u == v) continue;
            if (st[u].find(v) != st[u].end()) continue;
            vector<bool> vis(n);
            for (int x = (u + 1) % n; x != v; x = (x + 1) % n) {
                vis[x] = true;
            }
            bool ok = true;
            for (int x = (u + 1) % n; x != v; x = (x + 1) % n) {
                for (int y : st[x]) {
                    if (y == u || y == v) continue;
                    if (vis[y]) continue;
                    ok = false;
                    break;
                }
                if (!ok) break;
            }
            if (ok) {
                ++ans;
                st[u].emplace(v);
                st[v].emplace(u);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}