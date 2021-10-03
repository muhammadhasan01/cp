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
        if (pu < pv) {
            swap(pu, pv);
        }
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }
};

const int dy[] = {1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    int res = n * m + 5;
    vector<pair<int, int>> pos(res);
    vector<vector<int>> id(n + 1, vector<int>(m + 1));
    for (int i = 1, c = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            c = c + 1;
            id[i][j] = c;
            pos[c] = make_pair(i, j);
        }
    }
    DSU dsu(res);
    auto upd = [&](int i, int j) -> void {
        if (a[i][j] != 2) {
            return;
        }
        for (int k = 0; k < 2; k++) {
            int ci = i + dy[k];
            int cj = j;
            if (ci < 1 || ci > n) {
                continue;
            }
            if (a[ci][cj] == 2) {
                dsu.merge(id[i][j], id[ci][cj]);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            upd(i, j);
        }
    }
    for (int i = 0; i < k; i++) {
        int x = 1;
        int y;
        cin >> y;
        while (x <= n) {
            if (a[x][y] == 2) {
                int down = dsu.fpar(id[x][y]);
                auto [nx, ny] = pos[down];
                x = nx + 1;
            } else if (a[x][y] == 1) {
                a[x][y] = 2;
                upd(x, y);
                y = y + 1;
            } else if (a[x][y] == 3) {
                a[x][y] = 2;
                upd(x, y);
                y = y - 1;
            }
        }
        cout << y << " \n"[i == k - 1];
    }

    return 0;
}