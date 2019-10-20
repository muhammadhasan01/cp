#include <bits/stdc++.h>

using namespace std;

struct E {
    int u, v, c;
};

const int N = 2e5 + 5;
int n, m;
int par[N], sz[N];
E edge[N];
E tedge[N];
vector<pair<int,int>> g[N];
bool used[N], nc[N];

bool cmpr(E a, E b) {
    return (a.c < b.c);
}

int find(int x)  {
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

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].c;
        g[edge[i].u].push_back({edge[i].v, edge[i].c});
        g[edge[i].v].push_back({edge[i].u, edge[i].c});
    }

    sort(edge + 1, edge + 1 + m, cmpr);

    for (int i = 1; i <= n; i++) {
        par[i] = i, sz[i] = 1;
    }

    int total = 0;
    vector<int> msE;
    for (int i = 1; i <= m; i++) {
        int pu = find(edge[i].u);
        int pv = find(edge[i].v);
        if (pu != pv && total < n - 1) {
            msE.push_back(i);
            merge(pu, pv);
            total++;
        } else if (total == n - 1) {
            merge(pu, pv);
            
        }
    }

    cout << ans << '\n';

    return 0;
}
