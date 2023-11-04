#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int L = 18;
const int MOD = 1e9 + 7;

int n, m;
int q;
vector<int> adj[N];
set<int> g[N];
int tin[N], low[N], timer = 0;
int comp[N], numComponent;
stack<int> st;
bool onStack[N];
int up[N][L];
int cnt[N], tin_g[N], tout_g[N], tim = 0;
int cycle[N];
int dp[N];

void tarjan(int u, int p) {
    tin[u] = low[u] = ++timer;
    st.emplace(u);
    onStack[u] = true;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (tin[v] == 0) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] != low[u]) return;
    int w = 0;
    numComponent++;
    do {
        w = st.top(); st.pop();
        onStack[w] = 0;
        comp[w] = numComponent;
    } while (w != u && !st.empty());
}

void SCC() {
    for (int i = 1; i <= n; i++) {
        if (tin[i]) {
            continue;
        }
        tarjan(i, i);
    }
}

void processLCA(int u, int p) {
    cnt[u] = cycle[u] + (u == p ? 0 : cnt[p]);
    up[u][0] = p;
    tin_g[u] = ++tim;
    for (int i = 1; i < L; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
        if (v == p) {
            continue;
        }
        processLCA(v, u);
    }
    tout_g[u] = ++tim;
}

bool is_anc(int u, int v) {
    return (tin_g[u] <= tin_g[v] && tout_g[u] >= tout_g[v]);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) {
        return u;
    }
    if (is_anc(v, u)) {
        return v;
    }
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int distance(int u, int v) {
    int w = LCA(u, v);
    return cnt[u] + cnt[v] - 2 * cnt[w] + cycle[w];
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
    SCC();
    vector<int> vis(n + 1);
    for (int u = 1; u <= n; u++) {
        int cu = comp[u];
        for (int v : adj[u]) {
            int cv = comp[v];
            if (cu == cv) {
                continue;
            }
            g[cu].emplace(cv);
            g[cv].emplace(cu);
        }
        if (vis[cu]) {
            cycle[cu] = true;
        } else {
            vis[cu] = true;
        }
    }
    int root = comp[1];
    processLCA(root, root);
    for (int u = 1; u <= n; u++) {
        if (g[u].empty()) {
            continue;
        }
    }
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 1]) % MOD;
    }
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int cu = comp[u];
        int cv = comp[v];
        int res = distance(cu, cv);
        cout << dp[res] << '\n';
    }
    
    return 0;
}