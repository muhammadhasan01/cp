#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, m;
int par[N], sz[N];

int find(int x) {
    return (par[x] == x ? x : par[x] = find(par[x]));
}

void merge(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
        if (sz[pu] < sz[pv]) swap(pu, pv);
        sz[pu] += sz[pv];
        par[pv] = pu;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    vector<bool> vis(n + 3, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = find(i);
        if (!vis[k]) {
            vis[k] = 1;
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
