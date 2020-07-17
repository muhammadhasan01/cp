#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n, m;
int deg[N];
vector<pair<int, int>> adj[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        vector<pair<int, int>> edges(m + 1);
        for (int i = 1; i <= m; i++) {
            int t, u, v;
            cin >> t >> u >> v;
            if (t)
                deg[v]++, t = 0;
            else
                t = i;
            adj[u].emplace_back(v, t);
            if (t > 0) adj[v].emplace_back(u, t);
            edges[i] = make_pair(u, v);
        }
        queue<int> q;
        vector<bool> in(n + 1);
        vector<bool> vis(m + 1);
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0)
                q.emplace(i), in[i] = 1;
        }
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++cnt;
            for (auto e : adj[u]) {
                int v = e.first;
                int t = e.second;
                if (t == 0 && --deg[v] == 0) {
                    if (in[v] == 0) q.emplace(v), in[v] = 1;
                } else if (t > 0) {
                    if (vis[t]) continue;
                    vis[t] = 1;
                    if (edges[t].first == v)
                        swap(edges[t].first, edges[t].second);
                    if (in[v] == 0 && deg[v] == 0) q.emplace(v), in[v] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) adj[i].clear(), deg[i] = 0;
        if (cnt != n) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for (int i = 1; i <= m; i++) {
            cout << edges[i].first << " " << edges[i].second << '\n';
        }
    }

    return 0;
}