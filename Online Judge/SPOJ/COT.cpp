// TLE :(
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m;
vector<int> adj[N];
int val[N], id[N];
int depth[N], head[N], heavy[N], par[N];
int pos[N];
int curPos;
vector<int> t[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = vector<int>(1, val[id[s]]);
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        merge(t[v << 1].begin(), t[v << 1].end(), t[v << 1 | 1].begin(),
              t[v << 1 | 1].end(), back_inserter(t[v]));
    }
}

int get(int v, int s, int e, int l, int r, int val) {
    if (e < l || s > r || l > r) return 0;
    if (l <= s && e <= r) {
        cerr << "----\n";
        for (auto& e : t[v]) cerr << e << ' ';
        cerr << "\n---\n";
        int res = upper_bound(t[v].begin(), t[v].end(), val) - t[v].begin();
        return res;
    }
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, r, val);
    int p2 = get(v << 1 | 1, mid + 1, e, l, r, val);
    return p1 + p2;
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

int queryPath(int u, int v, int val) {
    int res = 0;
    for (; head[u] != head[v]; u = par[head[u]]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        res += get(1, 1, curPos, pos[head[u]], pos[u], val);
    }
    if (depth[u] > depth[v]) swap(u, v);
    res += get(1, 1, curPos, pos[u], pos[v], val);
    // cerr << res << '\n';
    return res;
}

void init() {
    dfs(1, 1);
    decompose(1, 1);
}

int main() {
	scanf("%d %d", &n, &m);
    vector<int> uniq(n), value(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
        uniq[i - 1] = val[i];
    }
    sort(uniq.begin(), uniq.end());
    uniq.resize(unique(uniq.begin(), uniq.end()) - uniq.begin());
    for (int i = 1; i <= n; i++) {
        val[i] = lower_bound(uniq.begin(), uniq.end(), val[i]) - uniq.begin();
    }
    int sz = uniq.size();
    for (int i = 0; i < sz; i++) {
        value[i] = uniq[i];
    }
    int u, v, k;
    for (int i = 1; i < n; i++) {
    	scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    init();
    build(1, 1, n);
    while (m--) {
    	scanf("%d %d %d", &u, &v, &k);
        int l = 0, r = sz - 1, ans = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (queryPath(u, v, mid) >= k) {
                ans = uniq[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    	printf("%d\n", ans);
    }

    return 0;
}