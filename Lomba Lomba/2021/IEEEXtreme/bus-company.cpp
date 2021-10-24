#include <bits/stdc++.h>

using namespace std;
using ll = __int128;

const int N = 2e5 + 10;
const int M = 2 * N;
const int L = ceil(log2(N)) + 3;
const int K = 2;

template<int MAXN, typename T, T TERM>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, TERM);
    }

    T combine(const T& x, const T& y) {
        return x + y;
    }

    void build(int v, int s, int e, vector<T>& a) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid, a);
            build(v << 1 | 1, mid + 1, e, a);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int s, int e, int pos, T val) {
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

    T get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        T p1 = get(v << 1, s, mid, l, r);
        T p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
};

int n, q;
vector<int> adj[N];
int up[N][L];
int col[N];
int depth[N], head[N], heavy[N];
int par[N], id[N], position[N];
int subsz[N];
int curPos;
int tin[M], tout[M], tim;
int eul[M];
ll t[K][4 * N], lazy[K][4 * N];
Segtree<M, ll, 0> sgt[2];

void build(int tp, int v, int s, int e) {
    lazy[tp][v] = 0;
    if (s == e) {
        t[tp][v] = 0;
    } else {
        int mid = (s + e) >> 1;
        build(tp, v << 1, s, mid);
        build(tp, v << 1 | 1, mid + 1, e);
        t[tp][v] = t[tp][v << 1] + t[tp][v << 1 | 1];
    }
}

void push(int tp, int v, int s, int e) {
    if (s == e) {
        return;
    }
    int mid = (s + e) >> 1;
    lazy[tp][v << 1] += lazy[tp][v];
    lazy[tp][v << 1 | 1] += lazy[tp][v];
    t[tp][v << 1] += lazy[tp][v] * (mid - s + 1);
    t[tp][v << 1 | 1] += lazy[tp][v] * (e - mid);
    lazy[tp][v] = 0; 
}

void update(int tp, int v, int s, int e, int l, int r, ll val) {
    if (l > r) {
        return;
    }
    if (l == s && e == r) {
        t[tp][v] += val * (e - s + 1);
        lazy[tp][v] += val;
        return;
    }
    push(tp, v, s, e);
    int mid = (s + e) >> 1;
    update(tp, v << 1, s, mid, l, min(r, mid), val);
    update(tp, v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
    t[tp][v] = t[tp][v << 1] + t[tp][v << 1 | 1];
}

ll get(int tp, int v, int s, int e, int l, int r) {
    if (l > r)
        return 0;
    if (l <= s && e <= r)
        return t[tp][v];
    push(tp, v, s, e);
    int mid = (s + e) >> 1;
    ll p1 = get(tp, v << 1, s, mid, l, min(r, mid));
    ll p2 = get(tp, v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
    return p1 + p2;
}

int dfs(int u, int p) {
    depth[u] = (u == p ? 0 : 1 + depth[p]);
    par[u] = p;
    int sz = 1, max_sz = 0;
    tin[u] = ++tim;
    eul[tim] = u;
    up[u][0] = p;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : adj[u]) {
        if (v == p) continue;
        int res = dfs(v, u);
        sz += res;
        if (res > max_sz)
            max_sz = res, heavy[u] = v; 
    }
    subsz[u] = sz;
    tout[u] = ++tim;
    eul[tim] = u;
    return sz;
}

void decompose(int u, int h) {
    head[u] = h;
    position[u] = ++curPos;
    id[curPos] = u;
    if (heavy[u])
        decompose(heavy[u], h);
    for (auto v : adj[u])
        if (v != par[u] && v != heavy[u])
            decompose(v, v);
}

ll queryPath(int tp, int u, int v) {
    ll res = 0;
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        res += get(tp, 1, 1, curPos, position[head[u]], position[u]); // segtree query
    }
    if (depth[u] > depth[v]) swap(u, v); // u will be the LCA
    res += get(tp, 1, 1, curPos, position[u], position[v]); // position[u] + 1, if it's an edge value
    return res;
}

void updatePath(int tp, int u, int v, int val) {
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        update(tp, 1, 1, curPos, position[head[u]], position[u], val); // segtree query
    }
    if (depth[u] > depth[v]) swap(u, v); // u will be the LCA
    update(tp, 1, 1, curPos, position[u], position[v], val); // position[u] + 1, if it's an edge value
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
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

int distance(int u, int v) {
    int w = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

void init() {
    dfs(1, 1);
    decompose(1, 1);
    int m = 2 * n;
    vector<vector<ll>> val(2, vector<ll>(m + 5));
    for (int i = 1; i <= m; i++) {
        int u = eul[i];
        val[col[u]][i] = depth[u];
    }
    for (int it = 0; it < 2; it++) {
        build(it, 1, 1, curPos);
        sgt[it].build(1, 1, m, val[it]);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    int m = 2 * n;
    for (int u = 1; u <= n; u++) {
        cin >> col[u];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    init();
    for (int u = 1; u <= n; u++) {
        updatePath(col[u], 1, u, 1);
    }
    auto transaction = [&](int u) {
        col[u] = 1 - col[u];
        updatePath(col[u], 1, u, 1);
        updatePath(1 - col[u], 1, u, -1);
        sgt[col[u]].update(1, 1, m, tin[u], depth[u]);
        sgt[col[u]].update(1, 1, m, tout[u], depth[u]);
        sgt[1 - col[u]].update(1, 1, m, tin[u], 0);
        sgt[1 - col[u]].update(1, 1, m, tout[u], 0);
    };
    auto get_count = [&](int x, int c) -> ll {
        ll ret = queryPath(c, x, x);
        return ret;
    };
    auto get_dist = [&](int x, int c) -> ll {
        return sgt[c].get(1, 1, m, tin[x], tout[x]) / 2 - get_count(x, c) * depth[x];
    };
    auto compute = [&](int x, int c) -> pair<ll, ll> {
        ll cx = get_count(x, c);
        ll dx = get_dist(x, c);
        return make_pair(cx, dx);
    };
    auto get_value_0 = [&](int u, int v, int c) -> pair<ll, ll> {
        // compute for v first
        auto [cv, dv] = compute(v, c);
        // time for the real stuff
        ll cu = 0, du = 0;
        int w = getNearestNode(v, u);
        int two = getNearestNode(u, 1);
        // count u
        ll count_one = get_count(1, c);
        cu = count_one - get_count(w, c);
        du = get_dist(1, c) - get_dist(w, c) - queryPath(c, two, w);
        du += 1LL * depth[u] * count_one - queryPath(c, two, u);
        ll dist = cu * cv * (distance(u, v)) + du * cv + dv * cu;
        return make_pair(dist, cu * cv);
    };
    auto get_value_1 = [&](int u, int v, int c) -> pair<ll, ll> {
        auto [cu, du] = compute(u, c);
        auto [cv, dv] = compute(v, c);
        ll dist = cu * cv * (distance(u, v)) + du * cv + dv * cu;
        return make_pair(dist, cu * cv);
    };
    auto comparison = [&](int u, int v) {
        int w = LCA(u, v);
        ll dw, cw;
        ll db, cb;
        if (w == u || w == v) {
            if (w == v) {
                swap(u, v);
            }
            auto [d1, c1] = get_value_0(u, v, 0);
            auto [d2, c2] = get_value_0(u, v, 1);
            dw = d1, cw = c1;
            db = d2, cb = c2;
        } else {
            auto [d1, c1] = get_value_1(u, v, 0);
            auto [d2, c2] = get_value_1(u, v, 1);
            dw = d1, cw = c1;
            db = d2, cb = c2;
        }
        if (cw == 0 && cb == 0) {
            cout << "TIE" << '\n';
        } else if (cw == 0) {
            cout << "B" << '\n';
        } else if (cb == 0) {
            cout << "A" << '\n';
        } else {
            __int128 lhs = __int128(1) * dw * cb;
            __int128 rhs = __int128(1) * db * cw;
            if (lhs == rhs || (cw == cb && cw == 0)) {
                cout << "TIE" << '\n';
            } else {
                cout << (lhs < rhs ? "A" : "B") << '\n';
            }
        }
    };
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int u;
            cin >> u;
            transaction(u);
        } else if (tp == 2) {
            int u, v;
            cin >> u >> v;
            comparison(u, v);
        }
    }

    return 0;
}