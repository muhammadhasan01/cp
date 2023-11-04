#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }

    bool isSameParent(int u, int v) {
        return fpar(u) == fpar(v);
    }

    int getSize(int x) {
        int px = fpar(x);
        return sz[px];
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    DSU dsu(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        deg[a[i]]++;
        dsu.merge(i, a[i]);
    }
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vector<int> p(n + 1);
    vector<bool> vis(n + 1);
    vector<bool> insideLoop(n + 1);
    set<int> minis;
    int idx = 0;
    for (int S = 1; S <= n; S++) {
        int P = dsu.fpar(S);
        if (vis[P]) {
            continue;
        }
        int startingLoop = -1;
        int u = P;
        vis[u] = true;
        while (1) {
            u = a[u];
            if (vis[u]) {
                startingLoop = u;
                break;
            }
            vis[u] = true;
        }
        assert(startingLoop != -1);
        pair<int, int> mn = {c[startingLoop], startingLoop};
        insideLoop[startingLoop] = true;
        for (int s = a[startingLoop]; s != startingLoop; s = a[s]) {
            insideLoop[s] = true;
            mn = min(mn, {c[s], s});
        }
        minis.emplace(mn.second);
    }
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 0) {
            q.emplace(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        p[++idx] = u;
        if (--deg[a[u]] == 0) {
            q.emplace(a[u]);
        }
    }
    for (int u : minis) {
        for (int s = a[u]; s != u; s = a[s]) {
            p[++idx] = s;
        }
        p[++idx] = u;
    }
    assert(idx == n);
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
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