#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, k;
vector<int> g[N];
vector<int> comp[2];
int col[N], par[N], depth[N];
int cycStart = -1, cycEnd = -1;

bool dfs(int u, int p) {
    col[u] = 1;
    int maxDepth = -1;
    int cu = -1;
    for (auto v : g[u]) {
        if (v == p) continue;
        if (col[v] == 1) {
            if (maxDepth < depth[v]) {
                maxDepth = depth[v];
                cu = v;
            }
        }
    }
    if (cu != -1) {
        cycEnd = u;
        cycStart = cu;
        return true;
    }
    for (auto v : g[u]) {
        if (v == p) continue;
        if (col[v] == 0) {
            par[v] = u;
            depth[v] = 1 + depth[u];
            if (dfs(v, u)) return true;
        }
    }
    col[u] = 2;
    return false;
}

void DP(int u, int p, int h) {
    comp[h].emplace_back(u);
    for (auto v : g[u]) {
        if (v == p) continue;
        DP(v, u, 1 - h);
    }
}

void answerOne() {
    int pos = 0;
    if ((int) comp[0].size() < (int) comp[1].size()) pos = 1;
    cout << 1 << '\n';
    int len = (k + 1) / 2;
    assert((int) comp[pos].size() >= len);
    for (int i = 1; i <= len; i++) {
        cout << comp[pos][i - 1] << (i == len ? '\n' : ' ');
    }
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == 0 && dfs(i, i)) break;
    }
    if (cycStart == -1) {
        DP(1, 1, 0);
        answerOne();
    }
    vector<int> cycle;
    cycle.emplace_back(cycStart);
    for (int u = cycEnd; u != cycStart; u = par[u])
        cycle.emplace_back(u);
    reverse(cycle.begin(), cycle.end());
    int len = cycle.size();
    if (len <= k) {
        cout << 2 << '\n';
        cout << len << '\n';
        for (int i = 0; i < len; i++) {
            cout << cycle[i] << (i == len - 1 ? '\n' : ' ');
        }
    } else {
        for (int i = 0; i < len; i++) {
            comp[(i & 1)].emplace_back(cycle[i]);
        }
        answerOne();
    }

    return 0;
}