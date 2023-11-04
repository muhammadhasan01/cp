#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n, m;
vector<int> adj[N];
bool vis[N];

void bfs(int s) {
    queue<int> q;
    q.emplace(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        cout << u << '\n';
        q.pop();
        for (int v : adj[u]) {
            if (vis[v]) {
                continue;
            }
            vis[v] = 1;
            q.emplace(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    bfs(0);
    
    return 0;
}