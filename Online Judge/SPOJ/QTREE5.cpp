#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

int n, q;
int nodes;
vector<int> adj[N];
deque<int> dist[N];
int parc[N], sz[N];
bool checked[N];
bitset<N> vis;
multiset<int> ans[N];

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

void upd(int u) {
    int curNode = u, cnt = 0;
    if (vis[u]) {
        while (1) {
            ans[u].erase(ans[u].find(dist[curNode][cnt++]));
            if (parc[u] == -1) break;
            u = parc[u];
        }
    } else {
        while (1) {
            ans[u].emplace(dist[curNode][cnt++]);
            if (parc[u] == -1) break;
            u = parc[u];
        }
    }
    vis[curNode] = 1 - vis[curNode];
}

int query(int u) {
    int ret = INF, cnt = 0;
    int curNode = u;
    while (1) {
        if (!ans[u].empty()) ret = min(ret, *ans[u].begin() + dist[curNode][cnt]);
        cnt++;
        if (parc[u] == -1) break;
        u = parc[u];
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    decompose(1, -1);
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &u, &v);
        if (u) {
            int res = query(v);
            if (res == INF) res = -1;
            printf("%d\n", res);
        } else {
            upd(v);
        }
    }
    return 0;
}