#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 5;
const int M = 1e5 + 5;
const int L = ceil(log2(N)) + 2;
const int block = 505;

struct query {
    int l, r, lc, idx;
    bool operator<(const query& other) {
        if (l / block == other.l / block)
            return r < other.r;
        return l / block < other.l / block;
    }
};

int n, m;
vector<int> adj[N];
int val[N], cnt[N];
int eul[2 * N];
int up[N][L], tin[N], tout[N], tim;
query qr[M];
int ans[M];
int res;
bitset<N> vis;

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < L; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    tin[u] = ++tim;
    eul[tim] = u;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = ++tim;
    eul[tim] = u;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void upd(int x) {
    if (vis[x] == 1) {
        if (--cnt[val[x]] == 0) --res;
    } else {
        if (++cnt[val[x]] == 1) ++res;
    }
    vis[x] = 1 - vis[x];
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<int> uniq(n);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        uniq[i - 1] = val[i];
    }
    sort(uniq.begin(), uniq.end());
    uniq.resize(unique(uniq.begin(), uniq.end()) - uniq.begin());
    for (int i = 1; i <= n; i++) {
        val[i] = lower_bound(uniq.begin(), uniq.end(), val[i]) - uniq.begin();
    }
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (tin[u] > tin[v]) swap(u, v);
        int w = lca(u, v);
        if (u == w)
            qr[i] = {tin[u], tin[v], w, i};
        else
            qr[i] = {tout[u], tin[v], w, i};
    }
    sort(qr + 1, qr + 1 + m);
    int curL = 1, curR = 0;
    for (int i = 1; i <= m; i++) {
        int L = qr[i].l, R = qr[i].r;
        while (curL < L) upd(eul[curL++]);
        while (curL > L) upd(eul[--curL]);
        while (curR < R) upd(eul[++curR]);
        while (curR > R) upd(eul[curR--]);
        if (eul[L] != qr[i].lc) upd(qr[i].lc);
        ans[qr[i].idx] = res;
        if (eul[L] != qr[i].lc) upd(qr[i].lc);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}