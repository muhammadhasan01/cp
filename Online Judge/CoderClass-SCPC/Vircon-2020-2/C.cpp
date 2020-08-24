#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int tc;
int n;
long long res;
int sz[N];
vector<int> adj[N];

void init() {
    res = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
}

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        res += (1LL) * (n - sz[v]) * (sz[v]);
        sz[u] += sz[v];
    }
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    cout << (2LL * res) << '\n';    
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}