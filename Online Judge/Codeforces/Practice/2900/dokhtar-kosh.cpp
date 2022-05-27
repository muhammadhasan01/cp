#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 5e5 + 5;
const int K = 22;
const int M = (1 << K);

int n;
int a[N], ans[N];
int bag[M];
int depth[N], sz[N], big[N];
int tin[N], tout[N], tim;
int eul[N];
int ret;
vector<pair<int, int>> adj[N];

void dfs0(int u) {
    sz[u] = 1;
    big[u] = -1;
    tin[u] = ++tim;
    eul[tim] = u;
    for (auto [v, val] : adj[u]) {
        depth[v] = depth[u] + 1;
        a[v] = (1 << val) ^ a[u];
        dfs0(v);
        sz[v] += sz[u];
        if (big[u] == -1 || sz[big[u]] < sz[v]) {
            big[u] = v;
        }
    }
    tout[u] = tim;
}

void dfs(int u, bool keep) {
    for (auto [v, _] : adj[u]) {
        if (v == big[u]) {
            continue;
        }
        dfs(v, false);
        ans[u] = max(ans[u], ans[v]);
    }
    if (big[u] != -1) {
        dfs(big[u], true);
        ans[u] = max(ans[u], ans[big[u]]);
    }
    for (auto [v, _] : adj[u]) {
        if (v == big[u]) {
            continue;
        }
        for (int t = tin[v]; t <= tout[v]; t++) {
            int x = eul[t];
            ret = max(ret, bag[a[x]] - depth[u] + depth[x] - depth[u]);
            for (int j = 0; j < K; j++) {
                ret = max(ret, bag[a[x] ^ (1 << j)] - depth[u] + depth[x] - depth[u]);
            }
        }
        for (int t = tin[v]; t <= tout[v]; t++) {
            int x = eul[t];
            bag[a[x]] = max(bag[a[x]], depth[x]);
        }
    }
    ret = max(ret, bag[a[u]] - depth[u]);
    for (int i = 0; i < K; i++) {
        ret = max(ret, bag[a[u] ^ (1 << i)] - depth[u]);
    }
    bag[a[u]] = max(bag[a[u]], depth[u]);
    ans[u] = max(ans[u], ret);
    if (!keep) {
        for (int t = tin[u]; t <= tout[u]; t++) {
            int x = eul[t];
            bag[a[x]] = -INF;
        }
        ret = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        char cc;
        cin >> p >> cc;
        adj[p].emplace_back(i, (int) (cc - 'a'));
    }
    dfs0(1);
    for (int val = 0; val < M; val++) {
        bag[val] = -INF; 
    }
    dfs(1, false);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    
    return 0;
}