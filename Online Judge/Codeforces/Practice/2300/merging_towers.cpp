#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    
    DSU(int _n) : n(_n), par(_n), sz(_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int fpar(int x) {
        return (par[x] == x ? x : fpar(par[x]));
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int sz = n + m;
    DSU dsu(sz + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dsu.merge(x, i + m);
    }
    vector<vector<int>> vals(sz + 1);
    for (int i = m + 1; i <= sz; i++) {
        vals[dsu.fpar(i)].emplace_back(i - m);
    }
    vector<bool> done(n + 1);
    done[0] = done[n] = true;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (dsu.fpar(i + m) == dsu.fpar(i + m + 1)) {
            done[i] = 1;
            continue;
        }
        ans++;
    }
    cout << ans << '\n';
    for (int T = 0; T < m - 1; T++) {
        int a, b;
        cin >> a >> b;
        int pa = dsu.fpar(a);
        int pb = dsu.fpar(b);
        if (dsu.sz[pa] < dsu.sz[pb]) {
            swap(pa, pb);
        }
        dsu.merge(pa, pb);
        while (!vals[pb].empty()) {
            int x = vals[pb].back();
            vals[pb].pop_back();
            vals[pa].emplace_back(x);
            for (int k = 0; k < 2; k++) {
                int y = x - k;
                if (done[y]) {
                    continue;
                }
                if (dsu.fpar(y + m) == dsu.fpar(y + m + 1)) {
                    ans--;
                    done[y] = true;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}