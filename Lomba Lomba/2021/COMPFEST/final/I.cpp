#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int B = 1e5 + 10;
const int L = ceil(log2(N)) + 2;

int n, q;
int val_node[N];
int val_edge[N];
int tin[N], tout[N], tim;
int depth[N], head[N], heavy[N];
int par[N], id[N], pos[N];
int curPos;
bool in_block[N];
long long t[4 * N];
int up[N][L];
vector<int> adj[N];
vector<int> node_blocks;

int getValue(int u, int v) {
    return max(abs(val_node[u] + val_node[v]), abs(val_node[u] - val_node[v]));
}

long long combine(long long u, long long v) {
    return u + v;
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = val_edge[id[s]];
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int s, int e, int pos, long long val) {
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

long long get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return 0LL;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    long long p1 = get(v << 1, s, mid, l, r);
    long long p2 = get(v << 1 | 1, mid + 1, e, l, r);
    return combine(p1, p2);
}

int dfs(int u, int p) {
    depth[u] = (u == p ? 0 : 1 + depth[p]);
    par[u] = p;
    tin[u] = ++tim;
    up[u][0] = p;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    int sz = 1, max_sz = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        val_edge[v] = getValue(u, v);
        int res = dfs(v, u);
        sz += res;
        if (res > max_sz)
            max_sz = res, heavy[u] = v; 
    }
    tout[u] = ++tim;
    return sz;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
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

long long queryPath(int u, int v) {
    long long res = 0;
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        long long curRes = get(1, 1, curPos, pos[head[u]], pos[u]); // segtree query
        res = combine(res, curRes);
    }
    if (depth[u] > depth[v]) swap(u, v); // u will be the LCA
    long long curRes = get(1, 1, curPos, pos[u] + 1, pos[v]); // pos[u] + 1, if it's an edge value
    res = combine(res, curRes);
    return res;
}

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int getNearestNode(int u, int v) {
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return u;
}

void init() {
    dfs(1, 1);
    decompose(1, 1);
    build(1, 1, curPos);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> val_node[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    init();
    auto update_query = [&](int u, int c) -> void {
        val_node[u] = c;
        int len = adj[u].size();
        if (len <= B) {
            for (int v : adj[u]) {
                int new_val = getValue(u, v);
                if (par[v] == u) {
                    val_edge[v] = new_val;
                    update(1, 1, curPos, pos[v], val_edge[v]);
                } else {
                    val_edge[u] = new_val;
                    update(1, 1, curPos, pos[u], val_edge[u]);
                }
            }
            return;  
        }
        if (!in_block[u]) {
            node_blocks.emplace_back(u);
        }
        in_block[u] = true;
    };
    auto get_query = [&](int u, int v) -> long long {
        long long ret = queryPath(u, v);
        int w = LCA(u, v);
        for (int x : node_blocks) {
            if (!is_anc(w, x)) {
                continue;
            }
            if (is_anc(x, u)) {
                if (x != u) {
                    int p = getNearestNode(u, x);
                    ret -= val_edge[p];
                    val_edge[p] = getValue(p, x);
                    ret += val_edge[p];
                }
            }
            if (is_anc(x, v)) {
                if (x != v) {
                    int p = getNearestNode(v, x);
                    ret -= val_edge[p];
                    val_edge[p] = getValue(p, x);
                    ret += val_edge[p];
                }
            }
            if (x != w) {
                ret -= val_edge[x];
                val_edge[x] = getValue(x, par[x]);
                ret += val_edge[x];
            }
        }
        return ret;
    };
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int u, c;
            cin >> u >> c;
            update_query(u, c);
        } else if (tp == 2) {
            int u, v;
            cin >> u >> v;
            long long res = get_query(u, v);
            cout << res << '\n';
        }
    }
    
    return 0;
}