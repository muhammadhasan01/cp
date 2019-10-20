#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = N * N + 5;
int n, m;
bool a[N][N];
int f[N][N];
int par[M], sz[M], edge[M];
int kk = 0;
bitset<M> b[M];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void merge(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
        if (sz[pu] < sz[pv]) swap(pu, pv);
        sz[pu] += sz[pv];
        edge[pu] += edge[pv];
        par[pv] = pu;
    }
}

void ufind(int x, int y) {
    //cerr << "cari " << x << " dan " << y << '\n';
    int cnt = 0;
    if (!(x & 1)) {
        for (int i = x - 1; i <= x + 1; i++) {
            if (a[i][y + 1]) {
                //cerr << "gabung UwU => " << f[x][y] << " " << f[i][y + 1] << '\n';
                merge(f[x][y], f[i][y + 1]);
                if (b[f[x][y]][f[i][y + 1]] == 0) cnt++;
                b[f[x][y]][f[i][y + 1]] = 1;
                b[f[i][y + 1]][f[x][y]] = 1;
            }
        }
        for (int i = x - 1; i <= x + 1; i++) {
            int k = (i == x ? y - 1 : y);
            if (a[i][k]) {
                //cerr << "gabung UwU => " << f[x][y] << " " << f[i][k] << '\n';
                merge(f[x][y], f[i][k]);
                if (b[f[x][y]][f[i][k]] == 0) cnt++;
                b[f[x][y]][f[i][k]] = 1;
                b[f[i][k]][f[x][y]] = 1;
            }
        }
    } else {
        for (int i = x - 1; i <= x + 1; i++) {
            int k = (i == x ? y + 1 : y);
            if (a[i][k]) {
                //cerr << "gabung UwU => " << f[x][y] << " " << f[i][k] << '\n';
                merge(f[x][y], f[i][k]);
                if (b[f[x][y]][f[i][k]] == 0) cnt++;
                b[f[x][y]][f[i][k]] = 1;
                b[f[i][k]][f[x][y]] = 1;
            }
        }
        for (int i = x - 1; i <= x + 1; i++) {
            int k = y - 1;
            if (a[i][k]) {
                //cerr << "gabung UwU => " << f[x][y] << " " << f[i][k] << '\n';
                merge(f[x][y], f[i][k]);
                if (b[f[x][y]][f[i][k]] == 0) cnt++;
                b[f[x][y]][f[i][k]] = 1;
                b[f[i][k]][f[x][y]] = 1;
            }
        }
    }
    int fp = find(f[x][y]);
    //cerr << x << " => " << y << " ==> " << " => " << fp << " +" << cnt << "\n";
    edge[fp] += cnt;
}

void debug() {
    cerr << "\n--DEBUG--\n";
    for (int i = 1; i <= kk; i++) {
        int k = find(i);
        cerr << i << " => " << k << " => " << sz[k] << " " << edge[k] << '\n';
    }
    cerr << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;


    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                f[i][j] = ++kk;
            }
        } else {
            for (int j = 1; j <= m - 1; j++) {
                cin >> a[i][j];
                f[i][j] = ++kk;
            }
        }
    }

    for (int i = 1; i <= kk; i++) {
        par[i] = i, sz[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j]) {
                    ufind(i, j);
                }
            }
        } else {
            for (int j = 1; j <= m - 1; j++) {
                if (a[i][j]) {
                    ufind(i, j);
                }
            }
        }
    }

    //debug();

    int q;
    cin >> q;
    while (q--) {
        char x;
        cin >> x;
        if (x == 'a') {
            int ux, uy;
            cin >> ux >> uy;
            a[ux][uy] = 1;
            ufind(ux, uy);
            //debug();
        } else if (x == 'k') {
            int ux, uy;
            cin >> ux >> uy;
            if (a[ux][uy]) {
                int pr = find(f[ux][uy]);
                //cerr << pr << " danne => " << sz[pr] << " " << edge[pr] << '\n';
                cout << 6 * sz[pr] - 2 * edge[pr] << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}
