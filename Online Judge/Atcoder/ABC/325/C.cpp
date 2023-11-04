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

const int K = 8;
const int DX[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int DY[] = {1, -1, 0, 0, -1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> id(h, vector<int>(w));
    vector<vector<char>> g(h, vector<char>(w));
    int curId = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
            id[i][j] = curId++;
        }
    }
    DSU dsu(h * w + 5);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] != '#') {
                continue;
            }
            for (int k = 0; k < K; k++) {
                int ci = i + DX[k];
                int cj = j + DY[k];
                if (ci < 0 || cj < 0 || ci >= h || cj >= w) {
                    continue;
                }
                if (g[ci][cj] == '#') {
                    dsu.merge(id[i][j], id[ci][cj]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int idx = id[i][j];
            if (g[i][j] == '#' && dsu.fpar(idx) == idx) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}