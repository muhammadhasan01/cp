#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
vector<int> adj[N];
vector<int> buds;
bool is_leaf[N];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }
    if (u == 1) {
        return;
    }
    is_leaf[u] = true;
    int cnt = 0;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (is_leaf[v]) {
            is_leaf[u] = false;
            cnt++;
        }
    }
    if (!is_leaf[u]) {
        buds.emplace_back(cnt);
    }
}

void init() {
    buds.clear();
    for (int u = 1; u <= n; u++) {
        adj[u].clear();
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
    int res = 0;
    int len = buds.size();
    for (int i = 0; i < len; i++) {
        res += buds[i] - (i > 0);
    }
    int cnt_leaf = 0;
    for (int v : adj[1]) {
        if (is_leaf[v]) {
            cnt_leaf++;
        }
    }
    if (cnt_leaf >= 1) {
        cout << max(cnt_leaf, res + (cnt_leaf - 1)) << '\n';
    } else {
        cout << res << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}