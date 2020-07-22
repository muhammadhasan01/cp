#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n, m;
pair<int, int> edges[N];
vector<pair<int, int>> adj[N], radj[N];
bool vis[N];
bool ok[N];

void dfs(int u) {
    vis[u] = 1;
    for (auto& e : adj[u]) {
        int v = e.first;
        int id = e.second;
        if (vis[v]) continue;
        ok[id] = 1;
        dfs(v);
    }
}

void dfs2(int u) {
    vis[u] = 1;
    for (auto& e : radj[u]) {
        int v = e.first;
        int id = e.second;
        if (vis[v]) continue;
        ok[id] = 1;
        dfs2(v);
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear(); radj[i].clear();
        vis[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        ok[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
        adj[u].emplace_back(v, i);
        radj[v].emplace_back(u, i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    dfs2(1);
    int cnt = m - 2 * n;
    for (int i = 1; i <= m; i++) {
        if (!ok[i]) {
            cout << edges[i].first << " " << edges[i].second << '\n';
            if (--cnt == 0) break;
        }
    }
    assert(cnt == 0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}