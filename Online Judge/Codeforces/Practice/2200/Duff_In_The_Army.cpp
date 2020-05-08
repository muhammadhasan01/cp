#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int L = ceil(log2(N)) + 3;
const int A = 10;
const int INF = 2e9;

int n, m, q;
vector<int> g[N];
vector<int> c[N];
int up[N][L];
int dist[N];
int nums[N][L][A];
int tin[N], tout[N], tim;

void add(int x, int y, int val) {
    if (val == 0 || val == INF) return;
    int pos = -1;
    for (int i = 0; i < A; i++) {
        if (nums[x][y][i] == 0) nums[x][y][i] = INF;
        if (val == nums[x][y][i]) return;
        if (val < nums[x][y][i]) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return;
    for (int i = A - 1; i >= pos + 1; i--) {
        nums[x][y][i] = nums[x][y][i - 1];
    }
    nums[x][y][pos] = val;
}

void dfs(int u, int p) {
    up[u][0] = p;
    for (auto v : c[p]) {
        add(u, 0, v);
    }
    for (int i = 1; i < L; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        for (auto v : nums[u][i - 1]) {
            add(u, i, v);
        }
        for (auto v : nums[up[u][i - 1]][i - 1]) {
            add(u, i, v);
        }
    }
    tin[u] = ++tim;
    for (auto v : g[u]) {
        if (v == p) continue;
        dist[v] = 1 + dist[u];
        dfs(v, u);
    }
    tout[u] = ++tim;
}

bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int get(int u, int v) {
    int w = lca(u, v);
    for (int i = 0; i < A; i++) nums[0][0][i] = INF;
    for (auto e : c[u]) {
        add(0, 0, e);
    }
    for (int i = L - 1; i >= 0; i--) {
        if (dist[up[u][i]] >= dist[w]) {
            for (auto v : nums[u][i]) {
                add(0, 0, v);
            }
            u = up[u][i];
        }
    }
    u = v;
    for (auto e : c[u]) {
        add(0, 0, e);
    }
    for (int i = L - 1; i >= 0; i--) {
        if (dist[up[u][i]] >= dist[w]) {
            for (auto v : nums[u][i]) {
                add(0, 0, v);
            }
            u = up[u][i];
        }
    }
    int ret = 0;
    for (int i = 0; i < A; i++) {
        if (nums[0][0][i] != INF) ret++;
        else break;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        c[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        sort(c[i].begin(), c[i].end());
        if ((int) c[i].size() > A) c[i].resize(A);
    }
    dfs(1, 1);
    while (q--) {
        int u, v, a;
        cin >> u >> v >> a;
        int sz = get(u, v);
        cout << min(a, sz) << ' ';
        for (int i = 0; i < min(a, sz); i++) {
            cout << nums[0][0][i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}