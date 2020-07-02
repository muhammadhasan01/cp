#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
int par[N], sz[N];
long long dp[N];
long long cur = 0;

struct E{
    int u, v, w;
};

E g[N];

bool cmpr(E a, E b) {
    return a.w < b.w;
}

int find(int x) {
    return (par[x] == x ? x : find(par[x]));
}

void merge(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
        if (sz[pu] < sz[pv]) swap(pu, pv);
        cur += (1LL) * sz[pu] * (1LL) * sz[pv];
        sz[pu] += sz[pv];
        par[pv] = pu;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int maks = -1;
    for (int i = 1; i <= n; i++) {
        par[i] = i, sz[i] = 1;
        if (i == n) break;
        cin >> g[i].u >> g[i].v >> g[i].w;
        maks = max(maks, g[i].w);
    }

    sort(g + 1, g + n, cmpr);
    for (int i = 1; i <= n - 1; i++) {
        merge(g[i].u, g[i].v);
        dp[g[i].w] = cur;
    }
    for (int i = 1; i <= maks; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
    }
    int x;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        x = min(x, maks);
        cout << dp[x] << (i == m ? '\n' : ' ');
    }

    return 0;
}
