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
};

const int K = 6;
const int dx[] = {0, 0, 1, 1, -1, 1};
const int dy[] = {1, -1, 0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
        mp[a[i]] = i;
    }
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        auto [x, y] = a[i];
        for (int it = 0; it < K; it++) {
            int cx = x + dx[it];
            int cy = y + dy[it];
            pair<int, int> cur = make_pair(cx, cy);
            if (mp.count(cur) > 0) {
                dsu.merge(i, mp[cur]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i == dsu.fpar(i)) {
            ++res;
        }
    }
    cout << res << '\n';
    
    return 0;
}