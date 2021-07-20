#include <bits/stdc++.h>

using namespace std;

struct Line {
    mutable long long m, c, p;
    bool operator<(const Line& o) const {
        return m < o.m;
    }
    bool operator<(long long x) const {
        return p < x;
    }
};

struct LineContainer: multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const long long INF = LLONG_MAX;
    long long div(long long a, long long b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = INF, 0;
        if (x->m == y->m) x->p = x->c > y->c ? INF : -INF;
        else x->p = div(y->c - x->c, x->m - y->m);
        return x->p >= y->p;
    }

    void add(long long m, long long c) {
        auto z = insert({m, c, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }

    long long query(long long x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.c;
    }
};

const int N = 1e5 + 5;

int n;
int a[N], b[N];
long long ans[N];
vector<int> adj[N];
int sz[N];

void dfs1(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p, LineContainer& cur) {
    int maks = -1, big_child = -1;
    bool leaf = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (sz[v] < maks) continue;
        maks = sz[v];
        big_child = v;
        leaf = false;
    }
    if (big_child != -1) {
        dfs2(big_child, u, cur);
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        if (v == big_child) continue;
        LineContainer temp;
        dfs2(v, u, temp);
        for (const Line& l: temp) {
            cur.add(l.m, l.c);
        }
    }
    if (!leaf) {
        ans[u] = -cur.query(a[u]);
    }
    cur.add(-b[u], -ans[u]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs1(1, 1);
    LineContainer cur;
    dfs2(1, 1, cur);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

    return 0;
}