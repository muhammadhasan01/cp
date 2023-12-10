#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> type(m), u(m), v(m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> type[i] >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        adj[u[i]].emplace_back(v[i]);
        adj[v[i]].emplace_back(u[i]);
    }
    
    vector<int> ori(n, -1);
    
    function<void(int)> dfs = [&](int u) {
        for (int v : adj[u]) {
            if (ori[v] == -1) {
                ori[v] = ori[u] ^ 1;
                dfs(v);
            } else if (ori[u] == ori[v]) {
                cout << "NO\n";
                exit(0);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (ori[i] == -1) {
            ori[i] = 0;
            dfs(i);
        }
    }
    
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
    
    queue<int> q;
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        if (type[i] - 1 == ori[u[i]]) {
            adj[u[i]].emplace_back(v[i]);
            deg[v[i]]++;
        } else {
            adj[v[i]].emplace_back(u[i]);
            deg[u[i]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.emplace(i);
        }
    }
    vector<int> coor(n);
    int cur = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        coor[u] = cur++;
        for (int v : adj[u]) {
            if (--deg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    if (cur != n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << "LR"[ori[i]] << " " << coor[i] << "\n";
    }
    
    return 0;
}