#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k;
vector<int> g[N];
int depth[N];
int sz[N];
int par[N];
int deg[N];
set<pair<int, int>, greater<pair<int, int>>> s;

void dfs(int u, int p) {
    par[u] = p;
    for (auto v : g[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        deg[u]++;
        dfs(v, u);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1);
    for (int i = 2; i <= n; i++) {
        if ((int) g[i].size() == 1) {
            s.insert({depth[i] - sz[i], i});
        }
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        pair<int, int> cur = *s.begin();
        s.erase(s.begin());
        ans += (1LL) * (cur.first);
        int parent = par[cur.second];
        sz[parent] += (1 + sz[cur.second]);
        if (--deg[parent] == 0)
            s.insert({depth[parent] - sz[parent], parent});
    }
    cout << ans << '\n';

    return 0;
}