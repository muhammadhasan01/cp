#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;

int n;
vector<int> adj[N];
int val[N], depth[N], head[N], heavy[N], par[N], pos[N], id[N];
int t[4 * N], lazy[4 * N], headsgt[4 * N], tail[4 * N], mid[4 * N];
int curPos;

int combine(int u, int v) {
    while (u > 0 && v > 0) {
        if (u > v) swap(u, v);
        v %= u;
    }
    return (u > v ? u : v);
}

void push(int v, int s, int e) {
    if (lazy[v] == 0 || s == e) return;
    headsgt[v << 1] += lazy[v], headsgt[v << 1 | 1] += lazy[v];
    tail[v << 1] += lazy[v], tail[v << 1 | 1] += lazy[v];
    lazy[v << 1] += lazy[v], lazy[v << 1 | 1] += lazy[v];
    t[v << 1] = combine(headsgt[v << 1], mid[v << 1]);
    t[v << 1 | 1] = combine(headsgt[v << 1 | 1], mid[v << 1 | 1]);
    lazy[v] = 0;
}

void pull(int v) {
    headsgt[v] = headsgt[v << 1]; tail[v] = tail[v << 1 | 1];
    mid[v] = combine(mid[v << 1], mid[v << 1 | 1]);
    mid[v] = combine(mid[v], abs(tail[v << 1] - headsgt[v << 1 | 1]));
    t[v] = combine(headsgt[v], mid[v]);
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = headsgt[v] = tail[v] = val[id[s]];
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        pull(v);
    }
}

void updateRange(int v, int s, int e, int l, int r, int val) {
    if (l > r) return;
    if (l == s && e == r) {
        lazy[v] += val, headsgt[v] += val, tail[v] += val;
        t[v] = combine(headsgt[v], mid[v]);
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), val);
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
    pull(v);
}

int get(int v, int s, int e, int l, int r) {
    if (l > r) return 0;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, min(r, mid));
    int p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
    return combine(p1, p2);
}

int dfs(int u, int p) {
    depth[u] = 1 + (u == p ? 0 : depth[p]);
    par[u] = p;
    int sz = 1, max_sz = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        int res = dfs(v, u);
        sz += res;
        if (res > max_sz)
            max_sz = res, heavy[u] = v; 
    }
    return sz;
}

void decompose(int u, int h) {
    head[u] = h, pos[u] = ++curPos;
    id[curPos] = u;
    if (heavy[u])
        decompose(heavy[u], h);
    for (auto v : adj[u])
        if (v != par[u] && v != heavy[u])
            decompose(v, v);
}

int queryPath(int u, int v) {
    int res = 0;
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        int curRes = get(1, 1, curPos, pos[head[u]], pos[u]);
        res = combine(res, curRes);
    }
    if (depth[u] > depth[v]) swap(u, v);
    int curRes = get(1, 1, curPos, pos[u], pos[v]);
    res = combine(res, curRes);
    return res;
}

void updatePath(int u, int v, int val) {
    int res = 0;
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        updateRange(1, 1, curPos, pos[head[u]], pos[u], val);
    }
    if (depth[u] > depth[v]) swap(u, v);
    updateRange(1, 1, curPos, pos[u], pos[v], val);
}

void init() {
    dfs(1, 1);
    decompose(1, 1);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int u, v, w, q;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        u++, v++;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    init();
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    build(1, 1, curPos);
    char tp;
    cin >> q;
    while (q--) {
        cin >> tp >> u >> v;
        u++, v++;
        if (tp == 'F') {
            cout << queryPath(u, v) << '\n';
        } else if (tp == 'C') {
            cin >> w;
            updatePath(u, v, w);
        } else {
            assert(false);
        }
    }

    return 0;
}