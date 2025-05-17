#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> col(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    vector<vector<int>> adj(n + 1);
    adj[0].emplace_back(1);
    adj[1].emplace_back(0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> par(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        par[u] = p;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
        }
    };

    dfs(0, 0);

    vector<int> val(n + 1);
    vector<int> above(3);
    int black = 0;
    int white = 0;
    set<int> st;
    for (int u = 1; u <= n; u++) {
        if (col[u] == 1) {
            int p = par[u];
            ++black;
            ++val[p];
            if (col[p] == 0) {
                ++white;
            }
            if (val[p] == 2) {
                st.emplace(p);
                above[1]++;
            }
            if (val[p] == 3) {
                st.erase(p);
                above[2]++;
            }
        }
    }
    while (q--) {
        int u;
        cin >> u;
        int p = par[u];
        col[u] ^= 1;
        if (col[u] == 1) {
            ++black;
            ++val[p];
            if (col[p] == 0) {
                white++;
            } 
            if (val[p] == 2) {
                st.emplace(p);
                above[1]++;
            }
            if (val[p] == 3) {
                st.erase(p);
                above[2]++;
            }
            white -= val[u];
        } else {
            --black;
            --val[p];
            if (col[p] == 0) {
                white--;
            }
            if (val[p] == 1) {
                st.erase(p);
                above[1]--;
            }
            if (val[p] == 2) {
                st.emplace(p);
                above[2]--;
            }
            white += val[u];
        }
        if (above[1] >= 2 || above[2] > 0 || black == 0 || white != 1) {
            cout << "No" << '\n';
            continue;
        }
        if (above[1] == 1 && (int) st.size() == 1 && col[par[*st.begin()]] == 1) {
            cout << "No" << '\n';
            continue;
        }
        cout << "Yes" << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}