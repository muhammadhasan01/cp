#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, m, c;
int par[N], sz[N];
int w[N], dp[N];
multiset<int, greater<int>> ms[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    if (w[u] != w[v]) return;
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        par[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        int k = fpar(i);
        ms[k].insert(dp[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            int k = fpar(x);
            auto it = *ms[k].begin();
            cout << it << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            int k = fpar(x);
            auto it = ms[k].lower_bound(dp[x]);
            ms[k].erase(it);
            dp[x] = y;
            ms[k].insert(dp[x]);
        }
    }

    return 0;
}
