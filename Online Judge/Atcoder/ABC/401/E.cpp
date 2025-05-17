#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<bool> vis(n + 1);
    vector<bool> can(n + 1);
    set<int> st;
    st.emplace(1);
    vis[1] = true;
    set<int> cand;
    for (int v : adj[1]) {
        cand.emplace(v);
    }
    while (1) {
        int len = (int) st.size();
        int mx = *prev(st.end());
        if (len == mx) {
            can[len] = true;
        }
        if (cand.empty() || len == n) {
            break;
        }
        int u = *cand.begin();
        cand.erase(cand.begin());
        st.emplace(u);
        vis[u] = true;
        for (int v : adj[u]) {
            if (vis[v]) {
                continue;
            }
            cand.emplace(v);
        }
    }
    set<int> S;
    for (int u = 1; u <= n; u++) {
        if (S.find(u) != S.end()) {
            S.erase(u);
        }
        for (int v : adj[u]) {
            if (v < u) {
                continue;
            }
            S.emplace(v);
        }
        if (can[u]) {
            cout << (int) S.size() << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    
    return 0;
}