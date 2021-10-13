#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int m = 2 * n;
    vector<int> eul(m + 1);
    vector<int> par(n + 1);
    int tim = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        par[u] = p;
        eul[++tim] = u;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
        }
        eul[++tim] = u;
    };
    auto ask = [&](int l, int r) -> int {
        vector<int> nodes(r - l + 1);
        for (int i = l, k = 0; i <= r; i++, k++) {
            nodes[k] = eul[i];
        }
        sort(nodes.begin(), nodes.end());
        nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
        int len = nodes.size();
        if (len == 1) {
            return 0;
        }
        cout << "? ";
        cout << len << " ";
        for (int i = 0; i < len; i++) {
            cout << nodes[i];
            if (i < len - 1) {
                cout << " ";
            }
        }
        cout << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    dfs(1, 1);
    int max_val = ask(1, m);
    int l = 1, r = m, at = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int cur_val = ask(1, mid);
        if (cur_val == max_val) {
            at = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    int node = eul[at];
    cout << "! " << par[node] << " " << node << endl;
    
    return 0;
}