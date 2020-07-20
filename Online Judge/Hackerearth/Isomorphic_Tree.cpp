#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9;
 
template<class T, T oo> struct Hungary {
    static const int MAXN = 1000 + 5;
    static const int MAXM = 1000 + 5;
    int nx, ny, maty[MAXM], frm[MAXM], used[MAXM];
    T cst[MAXN][MAXM], fx[MAXN], fy[MAXM], dst[MAXM];
    void init(int nx, int ny) {
        this->nx = nx, this->ny = ny;
        fill_n(fx, nx + 1, 0), fill_n(fy, ny + 1, 0);
        fill_n(maty, nx + 1, 0);
        for (int i = 0; i <= nx; i++) {
            fill_n(cst[i], ny + 1, oo);
        }
    }
    void add(int x, int y, int c) {
        cst[x][y] = c;
    }
    T mincost() {
        for (int x = 1; x <= nx; x++) {
            int y0 = 0;
            maty[0] = x;
            for (int y = 0; y <= ny; y++) {
                dst[y] = oo + 1;
                used[y] = 0;
            }
            do {
                used[y0] = 1;
                int x0 = maty[y0], y1;
                T delta = oo + 1;
                for (int y = 1; y <= ny; y++) if (!used[y]) {
                    T curdst = cst[x0][y] - fx[x0] - fy[y];
                    if (dst[y] > curdst) {
                        dst[y] = curdst;
                        frm[y] = y0;
                    }
                    if (delta > dst[y]) {
                        delta = dst[y];
                        y1 = y;
                    }
                }
                for (int y = 0; y <= ny; y++) if (used[y]) {
                    fx[maty[y]] += delta;
                    fy[y] -= delta;
                }
                else {
                    dst[y] -= delta;
                }
                y0 = y1;
            }
            while (maty[y0] != 0);
            do {
                int y1 = frm[y0];
                maty[y0] = maty[y1];
                y0 = y1;
            }
            while (y0);
        }
        T res = 0;
        for (int y = 1; y <= ny; y++) {
            int x = maty[y];
            if (cst[x][y] < oo) res += cst[x][y];
        }
        return res;
    }
};
Hungary<int, (int) INF> hungary;
 
const int N = 55;

int len[2];
vector<int> g[2][N];
int sz[2][N][N];
int dp[N][N][N][N];
 
void dfs(int tp, int u, int p) {
    sz[tp][u][p] = 1;
    for (auto v : g[tp][u]) {
        if (v == p) continue;
        dfs(tp, v, u);
        sz[tp][u][p] += sz[tp][v][u];
    }
}
 
int answer(int u, int pu, int v, int pv) {
    int& res = dp[u][pu][v][pv];
    if (res != -1) return res;
    vector<vector<int>> vv(2);
    for (auto x : g[0][u])
        if (x != pu)
            vv[0].emplace_back(x);
    for (auto y : g[1][v])
        if (y != pv) 
            vv[1].emplace_back(y);
    vector<int> vx(2);
    vx[0] = vv[0].size(), vx[1] = vv[1].size();
    int k = max(vx[0], vx[1]);
    vector<vector<int>> cst(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int cu = (i < vx[0] ? vv[0][i] : -1);
            int cv = (j < vx[1] ? vv[1][j] : -1);
            if (cu == -1) {
                cst[i][j] = sz[1][cv][v];
            } else if (cv == -1) {
                cst[i][j] = sz[0][cu][u];
            } else {
                cst[i][j] = answer(cu, u, cv, v);
            }
        }
    }
    hungary.init(k, k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            hungary.add(i + 1, j + 1, cst[i][j]);
        }
    }
    return res = hungary.mincost();
}
 
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    for (int it = 0; it < 2; it++) {
        cin >> len[it];
    }
    for (int it = 0; it < 2; it++) {
        for (int i = 1; i < len[it]; i++) {
            int u, v;
            cin >> u >> v; --u, --v;
            g[it][u].emplace_back(v);
            g[it][v].emplace_back(u);
        }
        for (int u = 0; u < len[it]; u++)
            dfs(it, u, u);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < len[0]; i++) {
        for (int j = 0; j < len[1]; j++) {
            cout << answer(i, i, j, j) << (j == len[1] - 1 ? '\n' : ' ');
        }
    }
 
    return 0;
}