const int N = 1e5 + 10;

vector<int> adj[N];
int depth[N], head[N], heavy[N], par[N], id[N], pos[N];
int curPos;
int t[4 * N];

int combine(int u, int v) {
    return (u > v ? u : v);
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = val[id[s]];
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int s, int e, int pos, int val) {
    if (s == e && s == pos) {
        t[v] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid)
        update(v << 1, s, mid, pos, val);
    else
        update(v << 1 | 1, mid + 1, e, pos, val);
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return 0;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, r);
    int p2 = get(v << 1 | 1, mid + 1, e, l, r);
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
        int curRes = get(1, 1, curPos, pos[head[u]], pos[u]); // segtree query
        res = combine(res, curRes);
    }
    if (depth[u] > depth[v]) swap(u, v); // u will be the LCA
    int curRes = get(1, 1, curPos, pos[u], pos[v]); // pos[u] + 1, if it's an edge value
    res = combine(res, curRes);
    return res;
}

int kthNode(int u, int v, int k) {
    int tu = u, tv = v;
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
    }
    int lca = (depth[u] < depth[v] ? u : v);
    int finalHead = head[u];
    u = tu, v = tv;
    for (int it = 0; it < 2; it++) {
        for (; head[u] != finalHead; u = par[head[u]]) {
            int curVal = pos[u] - pos[head[u]] + 1;
            if (k > curVal) {
                k -= curVal;
                continue;
            }
            return id[pos[u] - k + 1];
        }
        int curVal = pos[u] - pos[lca] + 1;
        if (k <= curVal)
            return id[pos[u] - k + 1];
        else
            k -= curVal;
        k = (depth[v] - depth[lca]) - k + 1;
        assert(k > 0);
        swap(u, v);
    }
    assert(false);
}

void init() {
    dfs(1, 1);
    decompose(1, 1);
}

void reset() {
    curPos = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        heavy[i] = 0;
    }
}

void output() {
    for (int i = 1; i <= n; i++) {
        cerr << i << ": ";
        cerr << pos[i] << " - " << head[i] << " - " << heavy[i] << "\n";
    }
}