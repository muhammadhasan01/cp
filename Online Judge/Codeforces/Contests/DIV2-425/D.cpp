#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int L = ceil(log2(N)) + 3;

int n, q;
int tin[N], tout[N], tim = 0;
int par[N][L];
int dist[N];
vector<int> g[N];

void dfs(int u, int p) {
    par[u][0] = p;
    for (int i = 1; i < L; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    tin[u] = ++tim;
    for (auto v : g[u]) {
        if (v == p) continue;
        dist[v] = 1 + dist[u];
        dfs(v, u);
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(par[u][i], v)) {
            u = par[u][i];
        }
    }
    return par[u][0];
}

int distance(int u, int v) {
    int w = lca(u, v);
    return dist[u] + dist[v] - 2 * dist[w];
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[i].emplace_back(x);
        g[x].emplace_back(i);
    }
    dfs(1, 1);
    vector<int> v(3);
    while (q--) {
        for (int it = 0; it < 3; it++) cin >> v[it];
        sort(v.begin(), v.end());
        int ans = 0;
        do {
            int s = v[0], f = v[1], t = v[2];
            int st = lca(s, t);
            int sf = lca(f, t);
            int cur = distance(s, f) - distance(t, s) + min(distance(st, t), distance(sf, t));
            ans = max(ans, cur);
        } while (next_permutation(v.begin(), v.end()));
        cout << ans + 1 << '\n';
    }

    return 0;
}