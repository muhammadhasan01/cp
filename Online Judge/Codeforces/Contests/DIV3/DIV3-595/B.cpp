#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int q;
int n, a[N];

int par[N], sz[N];

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
        par[pv] = pu;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            merge(i, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            cout << sz[find(i)] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
