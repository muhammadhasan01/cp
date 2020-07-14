#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define inchar          getchar
#define outchar(x)      putchar(x)

template < typename T > void inpos(T & x) {
    x = 0;
    register T c = inchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = inchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = inchar());
    for (; c > 47 && c < 58; c = inchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}
template < typename T > void outpos(T n) {
    if (n < 0) {
        outchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) outchar(snum[i--]);
    outchar('\n');
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
const int L = 19;

int n, m;
pair<int, int> nums[N];
int * adj[N];
int deg[N];
int a[N], id[N];
int up[N][L];
int tin[N], tout[N], tim = 0;
pvertex segtree[N];

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(a[s]);
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

int getQuery(pvertex u, pvertex v, pvertex w, pvertex pw, int s, int e, int val) {
    if (s == e) return s;
    int leftval = u->l->val + v->l->val - w->l->val - pw->l->val;
    int mid = (s + e) / 2;
    if (val <= leftval)
        return getQuery(u->l, v->l, w->l, pw->l, s, mid, val);
    else
        return getQuery(u->r, v->r, w->r, pw->r, mid + 1, e, val - leftval);
}

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < L; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    tin[u] = ++tim;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        segtree[v] = update(segtree[u], 1, n, a[v], 1);
        dfs(v, u);
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

int getz(int u, int v, int w, int pw, int val) {
    return getQuery(segtree[u], segtree[v], segtree[w], segtree[pw], 1, n, val);
}

int query(int u, int v, int k) {
    int w = LCA(u, v);
    int pw = (w == 1 ? 0 : up[w][0]);
    return id[getz(u, v, w, pw, k)];
}

int main() {
    inpos(n), inpos(m);
    segtree[0] = build(1, n);
    for (int i = 1; i <= n; i++) {
        inpos(a[i]);
        nums[i].first = a[i];
        nums[i].second = i;
    }
    sort(nums + 1, nums + 1 + n);
    for (int i = 1; i <= n; i++) {
        a[nums[i].second] = i;
        id[i] = nums[i].first;
    }
    segtree[1] = update(segtree[0], 1, n, a[1], 1);
    int u, v, k;
    for (int i = 1; i < n; i++) {
        inpos(u), inpos(v);
        nums[i].first = u, nums[i].second = v;
        deg[u]++, deg[v]++;
    }
    for (int i = 1; i <= n; i++) {
        adj[i] = new int[deg[i]];
        deg[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u = nums[i].first, v = nums[i].second;
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }
    dfs(1, 1);
    while (m--) {
        inpos(u), inpos(v), inpos(k);
        int res = query(u, v, k);
        outpos(res);
    }

    return 0;
}