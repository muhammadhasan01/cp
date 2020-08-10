#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 2 * N;

int n, m, k;
vector<int> adj[N];
int tin[N], tout[N], tim;
int depth[N], par[N];
int eul[M], id[M];
pair<int, int> t[4 * M];
int lazy[4 * M];
bool vis[N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = make_pair(eul[s], id[s]);
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void push(int v) {
    if (lazy[v] == 0) return;
    t[v << 1].first += lazy[v];
    t[v << 1 | 1].first += lazy[v];
    lazy[v << 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
    lazy[v] = 0;
}

void updateRange(int v, int s, int e, int l, int r, int val) {
    if (l > r) return;
    if (l == s && e == r) {
        t[v].first += val;
        lazy[v] += val;
        return;
    }
    push(v);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), val);
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

pair<int, int> getRange(int v, int s, int e, int l, int r) {
    if (l > r) return {0, id[s]};
    if (l <= s && e <= r) return t[v];
    push(v);
    int mid = (s + e) >> 1;
    pair<int, int> p1 = getRange(v << 1, s, mid, l, min(r, mid));
    pair<int, int> p2 = getRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
    return max(p1, p2);
}

void dfs(int u, int h) {
    tin[u] = ++tim; depth[u] = h;
    eul[tim] = h; id[tim] = u;
    for (auto& v : adj[u]) {
        dfs(v, h + 1);
    }
    tout[u] = ++tim;
    eul[tim] = h; id[tim] = u;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    par[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        par[i] = x;
        adj[x].emplace_back(i);
    }
    dfs(1, 1);
    m = 2 * n;
    build(1, 1, m);
    int ans = 0;
    for (int it = 1; it <= k; it++) {
        auto tmp = getRange(1, 1, m, 1, m);
        ans += tmp.first;
        int u = tmp.second;
        while (!vis[u]) {
            updateRange(1, 1, m, tin[u], tout[u], -1);
            vis[u] = 1;
            u = par[u];
        }
    }
    cout << ans << '\n';

    return 0;
}