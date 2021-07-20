#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int L = 22;

int q;
int up[N][L];
int vertex[N];
int dist[N], tin[N], tout[N], tim;
vector<int> adj[N];

void processLCA(int u, int p) {
    dist[u] = (u == p ? 0 : 1 + dist[p]);
    up[u][0] = p; tin[u] = ++tim;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : adj[u]) {
        if (v == p) continue;
        processLCA(v, u);
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int distance(int u, int v) {
    int w = LCA(u, v);
    return dist[u] + dist[v] - 2 * dist[w];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int u = 2; u <= 4; u++) {
        adj[1].emplace_back(u);
        adj[u].emplace_back(1);
    }
    cin >> q;
    {
        int node = 4;
        for (int i = 1; i <= q; i++) {
            int u;
            cin >> u;
            for (int j = node + 1; j <= node + 2; j++) {
                adj[u].emplace_back(j);
                adj[j].emplace_back(u);
            }
            node = node + 2;
            vertex[i] = u;
        }
    }
    processLCA(1, 1);
    {
        int furthest_node = 2;
        int diameter = 2;
        int node = 4;
        for (int i = 1; i <= q; i++) {
            for (int u : {node + 1, node + 2}) {
                if (dist[u] > dist[furthest_node]) {
                    furthest_node = u;
                    diameter = diameter + 1;
                } else {
                    diameter = max(diameter, distance(furthest_node, u));
                }
            }
            node = node + 2;
            cout << diameter << '\n';
        }
    }
    

    return 0;
}