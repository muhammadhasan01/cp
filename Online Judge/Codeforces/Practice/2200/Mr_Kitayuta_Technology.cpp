#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int tin[N], low[N], tim;
int comp[N], cmp;
int sz[N], par[N], szp[N];
bool onStack[N];
stack<int> st;
vector<int> g[N];

void dfs(int u) {
    tin[u] = low[u] = ++tim;
    st.emplace(u);
    onStack[u] = true;
    for (auto v : g[u]) {
        if (tin[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (low[u] == tin[u]) {
        int w = 0;
        cmp++;
        do {
            w = st.top();
            st.pop();
            comp[w] = cmp;
            sz[cmp]++;
            onStack[w] = false;
        } while (w != u && !st.empty());
    }
}

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    if (szp[pu] < szp[pv]) swap(pu, pv);
    szp[pu] += szp[pv];
    par[pv] = pu;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (tin[i] == 0) dfs(i);
    }
    for (int i = 1; i <= cmp; i++) {
        par[i] = i, szp[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : g[i]) {
            merge(comp[j], comp[i]);
        }
    }
    vector<int> noCycle(cmp + 1, 1);
    vector<int> res(cmp + 1);
    for (int i = 1; i <= cmp; i++) {
        int pi = fpar(i);
        if (sz[i] > 1) noCycle[pi] = 0;
        res[pi] += sz[i];
    }
    int ans = 0;
    for (int i = 1; i <= cmp; i++) {
        if (fpar(i) != i) continue;
        if (noCycle[i]) {
            ans += (szp[i] - 1);
        } else {
            ans += res[i];
        }
    }
    cout << ans << '\n';

    return 0;
}