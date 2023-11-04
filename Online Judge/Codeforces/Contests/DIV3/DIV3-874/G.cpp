#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    if (n % 3 != 0) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans;
    vector<int> par(n + 1, -1);
    vector<int> col(n + 1, -1);

    function<bool(int, int)> dfs = [&](int u, int p) {
        int numLeaf = 0, numMid = 0, numEnd = 0;
        int numChild = 0;
        for (auto [v, id] : adj[u]) {
            if (v == p) {
                continue;
            }
            par[v] = id;
            if (!dfs(v, u)) {
                return false;
            }
            numChild++;
            if (col[v] == 0) {
                numLeaf++;
            } else if (col[v] == 1) {
                numMid++;
            } else if (col[v] == 2) {
                numEnd++;
            }
        }
        if (numChild == numEnd) {
            col[u] = 0;
            return true;
        }
        if (numLeaf == 1 && numLeaf + numEnd == numChild) {
            col[u] = 1;
            return true;
        }
        if (numLeaf == 2 && numLeaf + numEnd == numChild) {
            col[u] = 2;
            if (u != 1) {
                ans.emplace_back(par[u]);
            }
            return true;
        }
        if (numMid == 1 && numMid + numEnd == numChild) {
            col[u] = 2;
            if (u != 1) {
                ans.emplace_back(par[u]);
            }
            return true;
        }
        return false;
    };

    if (!dfs(1, 1)) {
        cout << -1 << '\n';
        return;
    }
    if (col[1] != 2) {
        cout << -1 << '\n';
        return;
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
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