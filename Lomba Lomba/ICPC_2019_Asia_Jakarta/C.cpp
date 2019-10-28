#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, q;
bool a[N], b[N];
int par[N][2], sz[N][2];

int find_par(int x, int t) {
    if (par[x][t] == x) return x;
    return par[x][t] = find_par(par[x][t], t);
}

void merge(int u, int v, int t) {
    int pu = find_par(u, t);
    int pv = find_par(v, t);
    if (pu != pv) {
        if (sz[pu][t] < sz[pv][t]) swap(pu, pv);
        sz[pu][t] += sz[pv][t];
        par[pv][t] = pu;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = (x & 1);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[i] = (x & 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int t = 0; t < 2; t++) {
            par[i][t] = i, sz[i][t] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) merge(i, i + 1, 0);
        if (b[i] == b[i + 1]) merge(i, i + 1, 1);
    }

    while (q--) {
        int p1, q1, p2, q2;
        cin >> p1 >> q1 >> p2 >> q2;
        cout << ((find_par(p1, 0) == find_par(p2, 0) && find_par(q1, 1) == find_par(q2, 1)) ? "YES" : "NO") << '\n';
    }


    return 0;
}
