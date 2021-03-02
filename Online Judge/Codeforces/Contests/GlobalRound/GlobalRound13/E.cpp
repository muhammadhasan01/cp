#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 30;

int n;
int fib[30];
int sz[N], par[N], in[N];
bool vis[N];
vector<pair<int, int>> adj[N];

void dismiss() {
    cout << "NO" << '\n';
    exit(0);
}

int dfs(int u, int p, int k) {
    sz[u] = 1; par[u] = p;
    int ret = -1;
    for (auto& e : adj[u]) {
        int v; int id;
        tie(v, id) = e;
        if (vis[id] || v == p) continue;
        in[v] = id;
        int cur = dfs(v, u, k);
        if (cur != -1) ret = cur;
        sz[u] += sz[v];
    }
    if (sz[u] == fib[k - 1] || sz[u] == fib[k - 2]) {
        ret = u;
    }
    return ret;
}

void check(int u, int k) {
    if (fib[k] == 1) return;
    int x = dfs(u, u, k);
    if (x == -1) dismiss();
    int k1 = (sz[x] == fib[k - 1] ? k - 1 : k - 2);
    int k2 = (k1 == k - 2 ? k - 1 : k - 2);
    int y = par[x];
    vis[in[x]] = true;
    check(x, k1);
    check(y, k2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fib[0] = fib[1] = 1;
    for (int i = 2; i < K; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cin >> n;
    int k = -1;
    for (int i = 1; i < K; i++) {
        if (fib[i] == n) {
            k = i;
            break;
        }
    }
    if (k == -1) dismiss();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    check(1, k);
    cout << "YES" << '\n';

    return 0;
}