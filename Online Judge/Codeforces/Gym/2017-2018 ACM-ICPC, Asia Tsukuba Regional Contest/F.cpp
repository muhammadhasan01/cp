#include <bits/stdc++.h>

using namespace std;
using pli = pair<long long, int>;

const long long INF = 1e18;
const int N = 1e5 + 5;

int n, m;
int val_w[N];
pair<int, int> edges[N];
vector<pair<int, int>> adj[N];
vector<pair<int, int>> radj[N];
vector<pair<int, int>> adj_dijkstra[N];
long long dist[N][3];
bool visited[N];
int tin[N], low[N];
int timer;
bool in_dijsktra[N];
bool bridge[N];

void dijkstra(int s, bool reverse) {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int u = 1; u <= n; u++) {
        dist[u][s] = INF;
    }
    dist[s][s] = 0LL;
    pq.emplace(dist[s][s], s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u][s] < d) {
            continue;
        }
        auto& cur = adj[u]; 
        if (reverse) {
            cur = radj[u];
        }
        for (auto& [v, id] : cur) {
            if (dist[v][s] > dist[u][s] + val_w[id]) {
                dist[v][s] = dist[u][s] + val_w[id];
                pq.emplace(dist[v][s], v);
            }
        }
    }
}

void dfs(int u, int p = -1) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    for (auto& [v, id] : adj_dijkstra[u]) {
        if (v == p) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (tin[u] < low[v]) {
                bridge[id] = true;
            }
        }
    }
}

void find_bridges() {
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        auto& [u, v] = edges[i];
        cin >> u >> v >> val_w[i];
        adj[u].emplace_back(v, i);
        radj[v].emplace_back(u, i);
    }
    int source = 1;
    int target = 2;
    dijkstra(source, false);
    dijkstra(target, true);
    for (int i = 1; i <= m; i++) {
        auto& [u, v] = edges[i];
        if (dist[u][source] + dist[v][target] + val_w[i] == dist[target][source]) {
            adj_dijkstra[u].emplace_back(v, i);
            adj_dijkstra[v].emplace_back(u, i);
            in_dijsktra[i] = true;
        }
    }
    find_bridges();
    for (int i = 1; i <= m; i++) {
        if (bridge[i]) {
            cout << "SAD" << '\n';
        } else if (in_dijsktra[i]) {
            cout << "SOSO" << '\n';
        } else {
            auto& [u, v] = edges[i];
            if (dist[v][source] + val_w[i] + dist[u][target] < dist[target][source]) {
                cout << "HAPPY" << '\n';
            } else {
                cout << "SOSO" << '\n';
            }
        }
    }

    return 0;
}