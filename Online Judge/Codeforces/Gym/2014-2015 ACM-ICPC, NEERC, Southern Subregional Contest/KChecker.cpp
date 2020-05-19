// author: mhasan01
#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int L = ceil(log2(N)) + 3;

int n, m;
vector<int> g[N];
int tin[N], tout[N], tim;
int up[N][L];
int dist[N], a[N][N], c[N][N];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < L; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    tin[u] = ++tim;
    if (u != p) dist[u] = 1 + dist[p];
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = ++tim;
}

int is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int distance(int u, int v) {
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = distance(i, a[i][j]);
            cerr << c[i][j] << ' ';
            if (j > 1 && c[i][j] < c[i][j - 1]) {
                puts("WA gan :(");
                return 0;
            }
        } cerr << '\n';
    }
    puts("PRETEST PASSED!!");

    return 0;
}