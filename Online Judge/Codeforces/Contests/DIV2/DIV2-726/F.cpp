#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    vector<int> tgt(n);
    for (int i = 0; i < n; i++) {
        cin >> tgt[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> col(n, -1);
    for (int i = 0; i < n; i++) {
        if (col[i] != -1) {
            continue;
        }
        col[i] = 0;
        bool is_bipartite = true;
        queue<int> q;
        vector<long long> sum(2);
        q.emplace(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            sum[col[u]] += tgt[u] - val[u];
            for (int v : adj[u]) {
                if (col[v] == -1) {
                    col[v] = 1 - col[u];
                    q.emplace(v);
                } else if (col[v] == col[u]) {
                    is_bipartite = false;
                }
            }
        }
        if (is_bipartite) {
            if (sum[0] != sum[1]) {
                cout << "NO" << '\n';
                return;
            }
        } else {
            if (abs(sum[0] + sum[1]) % 2 == 1) {
                cout << "NO" << '\n';
                return;
            } 
        }
    }
    cout << "YES" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}