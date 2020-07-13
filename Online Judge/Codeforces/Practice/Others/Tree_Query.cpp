#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

struct item {
    long long key;
    int prior, cnt;
    item * l, * r;
    item() { }
    item(long long key) : key(key), prior(rng32()), cnt(1), l(NULL), r(NULL) { }
    
};
typedef item * pitem;

const int N = 1e5 + 10;
int n, q;
int nodes;
vector<pair<int, int>> adj[N];
deque<long long> dist[N];
int parc[N], sz[N];
bool checked[N];
pitem treaps[N], ptreaps[N];
int curNode;

int cnt(pitem t) {
    return t ? t->cnt : 0;
}

void upd(pitem t) {
    if (!t) return;
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(pitem t, pitem& l, pitem& r, long long key) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split(t->l, l, t->l, key),  r = t;
    else
        split(t->r, t->r, r, key),  l = t;
    upd(t);
}

void merge(pitem& t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r),  t = l;
    else
        merge(r->l, l, r->l),  t = r;
    upd(t);
}

void insert(pitem& t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split(t, it->l, it->r, it->key),  t = it;
    else
        insert(it->key < t->key ? t->l : t->r, it);
    upd(t);
}

int less_val(pitem t, long long val) {
    if (!t) return 0;
    if (t->key <= val)
        return 1 + cnt(t->l) + less_val(t->r, val);
    else
        return less_val(t->l, val);
}

void output(pitem t) {
    if (!t)  return;
    output(t->l);
    cout << t->key << ' ';
    output(t->r);
}

void dfs(int u, int p) {
    nodes++; sz[u] = 1;
    for (auto e : adj[u]) {
        int v = e.first;
        if (v == p || checked[v]) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p, long long d) {
    dist[u].emplace_front(d);
    pitem new_item = new item(d);
    insert(treaps[curNode], new_item);
    for (auto e : adj[u]) {
        int v = e.first;
        if (v == p || checked[v]) continue;
        long long curd = d + (1LL) * e.second;
        dfs2(v, u, curd);
    }
}

void dfs3(int u, int p, long long d) {
    pitem new_item = new item(d);
    insert(ptreaps[curNode], new_item);
    for (auto e : adj[u]) {
        int v = e.first;
        if (v == p || checked[v]) continue;
        long long curd = d + (1LL) * e.second;
        dfs3(v, u, curd);
    }
}

int centroid(int u, int p) {
    for (auto e : adj[u]) {
        int v = e.first;
        if (v == p || checked[v]) continue;
        if (sz[v] > nodes) return centroid(v, u);
    }
    return u;
}

void decompose(int u, int p, int d) {
    nodes = 0; dfs(u, u); nodes /= 2;
    int v = centroid(u, u);
    curNode = v;
    if (p != -1) dfs3(u, u, d);
    checked[v] = 1;
    dfs2(v, v, 0LL);
    parc[v] = p;
    for (auto e : adj[v]) {
        int w = e.first;
        if (checked[w]) continue;
        decompose(w, v, e.second);
    }
}

int query(int u, long long l) {
    int v = u, ret = 0, cnt = 0;
    long long val = l;
    while (1) {
        ret += less_val(treaps[v], val);
        if (parc[v] == -1) break;
        val = l - dist[u][++cnt];
        ret -= less_val(ptreaps[v], val);
        v = parc[v];
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) treaps[i] = ptreaps[i] = NULL;
    int u, v, w;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    decompose(1, -1, 0);
    long long l;
    while (q--) {
        cin >> u >> l;
        cout << query(u, l) << '\n';
    }

    return 0;
}