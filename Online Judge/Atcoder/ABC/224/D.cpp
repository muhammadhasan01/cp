#include <bits/stdc++.h>

using namespace std;

const int K = 12;
const int E = 8;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m;
    cin >> m;
    vector<vector<int>> adj(K);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    queue<vector<int>> q;
    map<vector<int>, int> dist;
    {
        vector<int> init(E);
        for (int i = 0; i < E; i++) {
            cin >> init[i];
        }
        dist[init] = 0;
        q.emplace(init);
    }
    while (!q.empty()) {
        vector<int> u = q.front();
        q.pop();
        vector<bool> vis(K);
        for (int pos : u) {
            vis[pos] = true;
        }
        for (int i = 0; i < E; i++) {
            int x = u[i];
            for (int y : adj[x]) {
                if (vis[y]) {
                    continue;
                }
                vector<int> v = u;
                v[i] = y;
                if (dist.find(v) == dist.end()) {
                    dist[v] = dist[u] + 1;
                    q.emplace(v);
                }
            }
        }
    }
    vector<int> ans(E);
    iota(ans.begin(), ans.end(), 1);
    if (dist.find(ans) == dist.end()) {
        cout << -1 << '\n';
        return 0;
    }
    cout << dist[ans] << '\n';
    
    return 0;
}