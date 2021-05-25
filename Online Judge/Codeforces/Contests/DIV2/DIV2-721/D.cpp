#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int lft, rgt;
int prev_lft, prev_rgt;
int sz[N], mini[N];
bool vis[N];
long long rem;
long long ans[N];
vector<int> adj[N];

void init() {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
    }
    rem = 1LL * n * (n - 1) / 2;
    lft = rgt = 0;
    prev_lft = prev_rgt = -1;
}

void dfs(int u, int p) {
    sz[u] = 1;
    mini[u] = u;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        mini[u] = min(mini[u], mini[v]);
    }
}

void find(int val) {
    if (lft == val || rgt == val) {
        long long sz_lft, sz_rgt;
        sz_lft = sz[lft];
        if (rgt != 0) {
            sz_rgt = sz[rgt];
        } else {
            sz_rgt = n - sz[prev_rgt];
        }
        long long cur = sz_lft * sz_rgt;
        ans[val] = rem - cur;
        rem = cur;
        return;
    }
    for (int u : adj[lft]) {
        if (u == prev_lft) continue;
        if (mini[u] != val) continue;
        if (lft == rgt) prev_rgt = u;
        prev_lft = lft;
        lft = u;
        vis[u] = 1;
        find(val);
        return;
    }
    for (int u : adj[rgt]) {
        if (u == prev_rgt) continue;
        if (mini[u] != val) continue;
        prev_rgt = rgt;
        rgt = u;
        vis[u] = 1;
        find(val);
        return;
    }
    ans[val] = rem;
    rem = 0;
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(0, 0);
    ans[0] = 0;
    for (int u : adj[0]) {
        ans[0] += 1LL * sz[u] * (sz[u] - 1) / 2;
    }
    rem -= ans[0];
    for (int i = 1; i <= n; i++) {
        if (vis[i] || rem == 0) {
            ans[i] = 0;
        } else {
            find(i);
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}