#include <bits/stdc++.h>
using namespace std;

struct E {
    int u, v;
};

const int N = 1e3 + 5;
int n, m, par[N], sz[N];
E edger[N];

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

    cin >> n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    int m = 0;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        int p1 = find(u), p2 = find(v);
        if (p1 == p2) {
            edger[++m].u = u;
            edger[m].v = v;
        } else {
            merge(u, v);
        }
    }
    cout << m << '\n';
    for (int i = 1; i <= m; i++) {
        int pr = find(edger[i].u);
        cout << edger[i].u << " " << edger[i].v << " ";
        for (int i = 1; i <= n; i++) {
            int pb = find(i);
            if (pr != pb) {
                cout << pr << " " << pb << '\n';
                merge(pr, pb);
                break;
            }
        }
    }

    return 0;
}
