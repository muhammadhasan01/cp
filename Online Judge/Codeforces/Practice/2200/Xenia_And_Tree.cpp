#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

int n, m;
int nodes;
vector<int> adj[N];
deque<int> dist[N];
int parc[N], sz[N];
bool checked[N];
int ans[N];

void dfs(int u, int p) {
    nodes++; sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p, int d) {
    dist[u].emplace_front(d);
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        dfs2(v, u, d + 1);
    }
}

int centroid(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p || checked[v]) continue;
        if (sz[v] > nodes) return centroid(v, u);
    }
    return u;
}

void decompose(int u, int p) {
    nodes = 0; dfs(u, u); nodes /= 2;
    int v = centroid(u, u);
    checked[v] = 1;
    dfs2(v, v, 0);
    parc[v] = p;
    for (auto w : adj[v]) {
        if (checked[w]) continue;
        decompose(w, v);
    }
}

void update(int u) {
    int curNode = u, cnt = 0;
    while (1) {
        ans[u] = min(ans[u], dist[curNode][cnt++]);
        if (parc[u] == -1) break;
        u = parc[u];
    }
}

int query(int u) {
    int curNode = u, cnt = 0, minD = INF;
    while (1) {
        minD = min(minD, dist[curNode][cnt++] + ans[u]);
        if (parc[u] == -1) break;
        u = parc[u];
    }
    return minD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    decompose(1, -1);
    fill(ans + 1, ans + 1 + n, INF);
    update(1);
    for (int i = 1; i <= m; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            update(x);
        } else if (t == 2) {
            cout << query(x) << '\n';
        }
    }

    return 0;
}