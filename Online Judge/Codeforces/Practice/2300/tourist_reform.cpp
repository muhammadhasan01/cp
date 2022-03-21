#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n, m;
vector<pair<int, int>> adj[N];
int tin[N], low[N], timer = 0;
int comp[N], numComponent;
stack<int> st;
bool onStack[N];

void tarjan(int u, int p) {
    tin[u] = low[u] = ++timer;
    st.emplace(u);
    onStack[u] = true;
    for (auto [v, id] : adj[u]) {
        if (v == p) {
            continue;
        }
        if (tin[v] == 0) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] != low[u]) return;
    int w = 0; numComponent++;
    do {
        w = st.top(); st.pop();
        onStack[w] = 0;
        comp[w] = numComponent;
    } while (w != u && !st.empty());
}

void SCC() {
    for (int i = 1; i <= n; i++) {
        if (tin[i]) continue;
        tarjan(i, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    SCC();
    vector<tuple<int, int, int>> ans;
    vector<int> cntComp(numComponent + 1);
    vector<bool> vis(n + 1);
    vector<bool> visEdge(m + 1);
    auto addEdge = [&](int u, int v, int id) -> void {
        if (visEdge[id]) {
            return;
        }
        visEdge[id] = true;
        ans.emplace_back(id, u, v);
    };
    for (int r = 1; r <= n; r++) {
        int cmp = comp[r];
        if (++cntComp[cmp] > 1) {
            continue;
        }
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            for (auto [v, id] : adj[u]) {
                if (comp[v] != cmp) {
                    continue;
                }
                addEdge(u, v, id);
                if (vis[v]) {
                    continue;
                }
                dfs(v);
            }
        };
        dfs(r);
    }
    int maxCntComp = -1;
    int rootComp = -1;
    for (int c = 1; c <= numComponent; c++) {
        if (cntComp[c] > maxCntComp) {
            maxCntComp = cntComp[c];
            rootComp = c;
        }
    }
    int rootNode = -1;
    for (int u = 1; u <= n; u++) {
        if (comp[u] == rootComp) {
            rootNode = u;
            break;
        }
    }
    fill(vis.begin(), vis.end(), false);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto [v, id] : adj[u]) {
            if (vis[v]) {
                continue;
            }
            addEdge(v, u, id);
            dfs(v);
        }
    };
    dfs(rootNode);
    sort(ans.begin(), ans.end());
    cout << maxCntComp << '\n';
    for (auto& [id, u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
    
    return 0;
}