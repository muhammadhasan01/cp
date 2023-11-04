#include <bits/stdc++.h>

using namespace std;

const int B = 550;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<vector<int>> larges(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if ((int) adj[v].size() >= B) {
                larges[u].emplace_back(v);
            }
        }
    }
    vector<int> lazy(n, -1);
    vector<int> val(n, -1);
    vector<int> last(n, -1);
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);

    auto propagate = [&](int u) -> void {
        for (int v : larges[u]) {
            if (lazy[v] > last[u]) {
                ans[u] = val[v];
                last[u] = lazy[v];
            }
        }
    };

    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        --u;
        propagate(u);
        int len = (int) adj[u].size();
        if (len < B) {
            for (int v : adj[u]) {
                ans[v] = ans[u];
                last[v] = i;
            }
        } else {
            lazy[u] = i;
            val[u] = ans[u];
        }
    }
    for (int i = 0; i < n; i++) {
        propagate(i);
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}