#include <bits/stdc++.h>

using namespace std;

const int N = 123456 + 5;
const int INF = 1e9;

int n, m;
vector<int> g[N];
int par[N];
int dist[N];
int eul[2 * N], tin[N], tout[N], tim;
int selectedEdges;
int t[8 * N], lazy[8 * N];
bitset<N> attacked;
bitset<N> vis;
int ansNode, ansTime;
int root;

void build(int v, int s, int e) {
    if (s == e) {
        int cur = eul[s];
        if (attacked[cur]) {
            t[v] = dist[cur];
        } else {
            t[v] = -INF;
        }
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

void push(int v, int s, int e) {
    if (s == e || lazy[v] == 0) return;
    t[v << 1] += lazy[v];
    t[v << 1 | 1] += lazy[v];
    lazy[v << 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
    lazy[v] = 0;
}

void updateRange(int v, int s, int e, int l, int r, int val) {
    if (l > r) return;
    if (l == s & e == r) {
        t[v] += val;
        lazy[v] += val;
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), val);
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (l > r) return -INF;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    return max(get(v << 1, s, mid, l, min(r, mid)),
               get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r));
}

void dfs(int u, int p) {
    par[u] = p;
    tin[u] = ++tim;
    eul[tim] = u;
    for (auto v : g[u]) {
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        dfs(v, u);
    }
    tout[u] = ++tim;
    eul[tim] = u;
}

void DP(int u, int p) {
    if (u != root) {
        if (vis[u] == 0) selectedEdges++;
        updateRange(1, 1, n, 1, n, 1);
        updateRange(1, 1, n, tin[u], tout[u], -2);
    }
    int curTime = 2 * selectedEdges - get(1, 1, n, 1, n);
    if (curTime < ansTime) {
        ansTime = curTime;
        ansNode = u;
    } else if (curTime == ansTime && u < ansNode) {
        ansNode = u;
    }
    for (auto v : g[u]) {
        if (v == p) continue;
        DP(v, u);
    }
    if (u != root) {
        if (vis[u] == 0) selectedEdges--;
        updateRange(1, 1, n, 1, n, -1);
        updateRange(1, 1, n, tin[u], tout[u], 2);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        root = x;
        attacked[x] = 1;
    }
    dfs(root, root);
    vis[root] = 1;
    for (int i = 1; i <= n; i++) {
        if (attacked[i] == 0) continue;
        int x = i;
        while (vis[x] == 0) {
            vis[x] = 1;
            x = par[x];
            selectedEdges++;
        }
    }
    n = 2 * n;
    build(1, 1, n);
    ansNode = root;
    ansTime = 2 * selectedEdges - get(1, 1, n, 1, n);
    DP(root, root);
    cout << ansNode << "\n" << ansTime << "\n";

    return 0;
}