#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n, m;
int p[N], h[N];
vector<int> adj[N];
int goodz[N];
bool ok;

void dfs(int u, int par) {
    if (!ok) return;
    for (auto v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
    if (h[u] < -p[u] || h[u] > p[u] || abs(h[u] + p[u]) % 2 == 1) {
        ok = false;
        return;
    }
    int good = (h[u] + p[u]) / 2;
    if (good < goodz[u] || good > p[u]) {
        ok = false;
        return;
    }
    if (u != par) {
        goodz[par] += good;
        p[par] += p[u];
    }
}

void init() {
    ok = true;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        goodz[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    cout << (ok ? "YES" : "NO") << '\n';
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