#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k;
int par[N], sz[N];
bitset<N> vis;

int findp(int x) {
    if (par[x] == x) return x;
    return par[x] = findp(par[x]);
}

void merge(int u, int v) {
    int pu = findp(u);
    int pv = findp(v);
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

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++) {
        int pi = findp(i);
        if (!vis[pi]) {
            vis[pi] = 1;
            k -= (sz[pi] - 1);
        }
    }
    cout << k << '\n';

    return 0;
}
