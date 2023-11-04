#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int N = 3e5 + 5;

int tc;
int n, _u, _v, _k;
string str;
int val[N];
vector<int> adj[N];
int depth[N];
int head[N], heavy[N], par[N];
int pos[N], id[N];
int curPos;
int t[4 * N];

int combine(int u, int v) {
    return u | v;
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = val[s];
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
    if (depth[u] > depth[v]) swap(u, v);
    int lastRes = get(1, 1, curPos, pos[u], pos[v]);
    res = combine(res, lastRes);
    return res;
}

int distance(int u, int v) {
    int tu = u, tv = v;
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
    }
    int lca = (depth[u] < depth[v] ? u : v);
    return depth[u] + depth[v] - 2 * depth[lca];
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

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> _u >> _v;
            adj[_u].emplace_back(_v);
            adj[_v].emplace_back(_u);
        }
        init();
        for (int i = 1; i <= n; i++) {
            val[pos[i]] = a[i];
        }
        build(1, 1, curPos);
        int Q;
        cin >> Q;
        while (Q--) {
            cin >> _u >> _v;
            int nodes = distance(_u, _v) + 1;
            int mid = (nodes + 1) / 2;
            int midNode = kthNode(_u, _v, mid);
            debug() << imie(nodes) imie(mid) imie(midNode);
            debug() << imie(queryPath(_u, midNode));
            debug() << imie(queryPath(midNode, _v)); 
            cout << __builtin_popcount(queryPath(_u, midNode)) +  __builtin_popcount(queryPath(midNode, _v)) << '\n';
        }
        reset();
    }

    return 0;
}