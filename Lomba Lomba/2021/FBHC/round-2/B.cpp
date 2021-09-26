#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 10;

int n;
vector<int> adj[N];
int depth[N], head[N], heavy[N];
int par[N], id[N], pos[N];
int curPos;
int t[4 * N], lazy[4 * N];

int combine(int u, int v) {
    return (u > v ? u : v);
}

void build(int v, int s, int e) {
    lazy[v] = 0;
    if (s == e) {
        t[v] = 0;
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void push(int v) {
    lazy[v << 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
    t[v << 1] += lazy[v];
    t[v << 1 | 1] += lazy[v];
    lazy[v] = 0; 
}

void update(int v, int s, int e, int l, int r, int val) {
    if (l > r) {
        return;
    }
    if (l == s && e == r) {
        t[v] += val;
        lazy[v] += val;
        return;
    }
    push(v);
    int mid = (s + e) >> 1;
    update(v << 1, s, mid, l, min(r, mid), val);
    update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
    t[v] = t[v << 1] + t[v << 1 | 1];
}

int get(int v, int s, int e, int l, int r) {
    if (l > r)
        return 0;
    if (l <= s && e <= r)
        return t[v];
    push(v);
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, min(r, mid));
    int p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
    return p1 + p2;
}

int dfs(int u, int p) {
    depth[u] = (u == p ? 0 : 1 + depth[p]);
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
        int curRes = get(1, 1, curPos, pos[head[u]], pos[u]); // segtree query
        res = combine(res, curRes);
    }
    if (depth[u] > depth[v]) swap(u, v); // u will be the LCA
    int curRes = get(1, 1, curPos, pos[u] + 1, pos[v]); // pos[u] + 1, if it's an edge value
    res = combine(res, curRes);
    return res;
}

void updatePath(int u, int v) {
    int res = 0;
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        update(1, 1, curPos, pos[head[u]], pos[u], 1); // segtree query
    }
    if (depth[u] > depth[v]) swap(u, v); // u will be the LCA
    update(1, 1, curPos, pos[u] + 1, pos[v], 1); // pos[u] + 1, if it's an edge value
}

void init() {
    dfs(1, 1);
    decompose(1, 1);
    build(1, 1, curPos);
}

void reset() {
    curPos = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        heavy[i] = 0;
    }
}

void solve() {
    cin >> n;
    reset();
    vector<pair<int, int>> edges(n - 1);
    for (int i = 1; i < n; i++) {
        auto& [u, v] = edges[i - 1];
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    init();
    vector<int> last(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (last[x] > 0) {
            updatePath(last[x], i);
        }
        last[x] = i;
    }
    int ans = 0;
    for (auto& [u, v] : edges) {
        int res = queryPath(u, v);
        if (res == 0) {
            ++ans;
        } 
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}