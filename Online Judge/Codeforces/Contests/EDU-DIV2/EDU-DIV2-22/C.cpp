#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int L = ceil(log2(N)) + 2;

int n, x;
vector<int> adj[N];
int up[N][L];
int depth[N], tin[N], tout[N], tim;

void processLCA(int u, int p) {
    depth[u] = (u == p ? 0 : 1 + depth[p]);
    up[u][0] = p; tin[u] = ++tim;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : adj[u]) {
        if (v == p) continue;
        processLCA(v, u);
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v) { return (tin[u] <= tin[v] && tout[u] >= tout[v]); }

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
    return depth[u] + depth[v] - 2 * depth[w];
}


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    processLCA(1, 1);
    vector<int> leaves;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((int) adj[i].size() > 1) continue;
        int w = LCA(i, x);
        if (distance(1, w) <= distance(w, x)) continue;
        ans = max(ans, 2 * depth[i]);
    }
    cout << ans << '\n';

    return 0;
}