#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n, m, q;
vector<int> g[N];
int par[N], sz[N], len[N];

int maks, maks_u;

int fpar(int x) {
    return (x == par[x] ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
}

void dfs(int u, int v = -1, int dist = 0) {
    if (dist > maks) maks = dist, maks_u = u;
    for (auto w : g[u]) {
        if (w == v) continue;
        dfs(w, u, dist + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (fpar(i) == i) {
            maks = -1; dfs(i);
            maks = -1; dfs(maks_u);
            len[i] = maks;
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            cout << len[fpar(x)] << '\n';
        } else if (t == 2) {
            int u, v;
            cin >> u >> v;
            int pu = fpar(u), pv = fpar(v);
            if (pu == pv) continue;
            merge(pu, pv);
            int p = fpar(u);
            len[p] = max((len[pu] + 1) / 2 + (len[pv] + 1) / 2 + 1, max(len[pu], len[pv]));
        }
    }


    return 0;
}
