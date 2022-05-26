#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int L = 20;

int n, q;
int up[N][L];
int depth[N], tin[N], tout[N], tim;
vector<int> adj[N];

void processLCA(int u, int p) {
    depth[u] = (u == p ? 0 : 1 + depth[p]);
    up[u][0] = p; tin[u] = ++tim;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : adj[u]) {
        if (v == p) continue;
        processLCA(v, u);
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int distance(int u, int v) {
    int w = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    processLCA(1, 1);
    vector<bool> important(n + 1);
    vector<vector<int>> aux(n + 1);
    auto solve = [&]() -> void {
        int len;
        cin >> len;
        vector<int> nodes(len);
        set<int> inp_nodes;
        for (int i = 0; i < len; i++) {
            cin >> nodes[i];
            inp_nodes.emplace(nodes[i]);
        }
        // corner case
        if (len == 1) {
            cout << 0 << '\n';
            return;
        }
        // check for adjacency
        for (int u : nodes) {
            if (u == 1) {
                continue;
            }
            int v = up[u][0];
            if (inp_nodes.find(v) != inp_nodes.end()) {
                cout << -1 << '\n';
                return;
            }
        }
        // answer for most queries
        sort(nodes.begin(), nodes.end(), [&](int x, int y) {
            return tin[x] < tin[y];
        });
        for (int u : nodes) {
            important[u] = true;
        }
        // find consecutive LCAs
        set<int> sts;
        for (int i = 1; i < len; i++) {
            int u = nodes[i - 1];
            int v = nodes[i];
            int w = LCA(u, v);
            for (int x : {u, v, w}) {
                sts.emplace(x);
            }
        }
        // union the nodes with the LCAs
        nodes.clear();
        for (int u : sts) {
            nodes.emplace_back(u);
        }
        sort(nodes.begin(), nodes.end(), [&](int x, int y) {
            return tin[x] < tin[y];
        });
        // create the auxilary tree
        vector<int> st;
        for (int u : nodes) {
            while (!st.empty()) {
                int v = st.back();
                if (!is_anc(v, u)) {
                    st.pop_back();
                } else {
                    aux[v].emplace_back(u);
                    break;
                }
            }
            st.emplace_back(u);
        }
        int ans = 0;
        // time for some dfs
        function<void(int)> dfs = [&](int u) {
            int c = 0;
            for (int v : aux[u]) {
                dfs(v);
                if (important[v]) {
                    c++;
                }
            }
            if (important[u]) {
                ans += c;
            } else {
                if (c > 1) {
                    ans++;
                } else if (c == 1) {
                    important[u] = true;
                }
            }
        };
        int s = nodes[0];
        dfs(s);
        cout << ans << '\n';
        // reset the stuff
        for (int u : nodes) {
            aux[u].clear();
            important[u] = false;
        }
    };
    cin >> q;
    while (q--) {
        solve();
    }
    
    return 0;
}