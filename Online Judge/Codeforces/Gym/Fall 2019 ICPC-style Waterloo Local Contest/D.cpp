#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar('\n');
}

struct vertex {
    int val;
    vertex *l, *r;
    vertex(int val) : val(val), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r) : val(0), l(l), r(r) {
        if (l) val += l->val;
        if (r) val += r->val;
    }
};
typedef vertex* pvertex;

const int N = 100005;
const int T = 20000;
const int SQRT = 150;
const int L = 18;

int n, q;
vector<pair<int, int>> adj[N];
int up[N][L], cnt[T + 5];
int tin[N], tout[N], tim = 0;
pvertex segtree[N];
int pre[N][SQRT], haha[N][SQRT];
int head[N], heavy[N], dep[N];
int pos[N];
 
int dfs_init(int node, int p){
    if (node != p) dep[node] = dep[p] + 1;
    int ret = 1, mx = 0;
    for (auto x : adj[node]){
        if (x.first == p) continue;
        int cur = dfs_init(x.first, node);
        ret += cur;
        if (mx < cur){
            mx = cur;
            heavy[node] = x.first;
        }
    }
    return ret;
}

void decompose(int node, int h){
    head[node] = h;
    pos[node] = tim++;
    if (heavy[node]){
        decompose(heavy[node], h);
    }
    for (auto x : adj[node]){
        if (x.first == up[node][0] || x.first == heavy[node]) continue;
        decompose(x.first, x.first);
    }
}

void init_hld(){
    tim = 0;
    dfs_init(1, 1);
    decompose(1, 1);
 
    for (int i=2;i<=n;i++){
        int edge;
        for (auto x : adj[i]){
            if (x.first == up[x.first][0]){
                edge = x.second;
                break;
            }
        }
        int id = pos[i];
        for (int j=1;j<SQRT;j++){
            pre[id][j] = (edge - 1) / j;
            haha[id][j] = (edge - 1) / j;
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<SQRT;j++){
            pre[i][j] += pre[i - 1][j];
        }
    }
}
 

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(0);
    int mid = (s + e) >> 1;
    return new vertex(build(s, mid), build(mid + 1, e));
}

pvertex update(pvertex v, int s, int e, int pos, int val) {
    if (s == e && s == pos)
        return new vertex(val);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(update(v->l, s, mid, pos, val), v->r);
    else
        return new vertex(v->l, update(v->r, mid + 1, e, pos, val));
}

int getQuery(pvertex u, pvertex v, pvertex w, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return 0;
    if (l <= s && e <= r) return u->val + v->val - 2 * w->val;
    int mid = (s + e) >> 1;
    int p1 = getQuery(u->l, v->l, w->l, s, mid, l, r);
    int p2 = getQuery(u->r, v->r, w->r, mid + 1, e, l, r);
    return p1 + p2;
}

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < L; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    tin[u] = ++tim;
    for (auto e : adj[u]) {
        int v = e.first;
        if (v == p) continue;
        int w = e.second;
        dep[v] = 1 + dep[u];
        segtree[v] = update(segtree[u], 1, T, w, ++cnt[w]);
        dfs(v, u);
        --cnt[w];
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int getz(int u, int v, int w, int val) {
    return getQuery(segtree[u], segtree[v], segtree[w], 1, T, 1, val);
}

int queryLarge(int u, int v, int k) {
    int w = LCA(u, v);
    int nodes = dep[u] + dep[v] - 2 * dep[w] + 1;
    int ret = nodes;
    for (int i = 1; i <= T; i++) {
        if (k * i > T) break;
        int R = getz(u, v, w, min(T, k * (i + 1)));
        int L = getz(u, v, w, k * i);
        ret += i * (R - L);
    }
    return ret;
}

int querySmall(int a, int b, int x){ // query for x < sqrt(T_MAX) (harus ditambah node di pathnya)
    int ret = dep[a] + dep[b] - 2 * dep[LCA(a, b)] + 1;
    for (; head[a] != head[b]; b = up[head[b]][0]){
        if (dep[head[a]] > dep[head[b]]) swap(a, b);
        ret += (pre[pos[b]][x] - pre[pos[head[b]]][x] + haha[pos[head[b]]][x]);
    }
    if (a == b) return ret;
    if (dep[a] > dep[b]) swap(a, b);
    ret += (pre[pos[b]][x] - pre[pos[a]][x]);
    return ret;
}

int main() {
    inpos(n), inpos(q);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        inpos(u), inpos(v), inpos(w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    segtree[1] = build(1, T);
    dfs(1, 1);
    init_hld();
    while (q--) {
        int S, F, t;
        inpos(S), inpos(F), inpos(t);
        int res;
        if (T >= SQRT) {
            res = queryLarge(S, F, t);
        } else {
            res = queryLarge(S, F, t);
        }
        outpos(res);
    }
    return 0;
}