#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k;
int a[N];
vector<int> adj[N];
int dp[N];
bool available[N];
bool okay;
int xor_a = 0;

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dp[i] = 0;
        available[i] = 0;
    }
}

void dfs(int u, int p) {
    dp[u] = a[u];
    int c = 0;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        dp[u] = (dp[u] ^ dp[v]);
        if (available[v]) {
            available[u] = true;
            c += 1;
        }
    }
    if (c > 1) {
        okay = true;
    }
    if (dp[u] == 0 && c > 0) {
        okay = true;
    }
    if (dp[u] == xor_a) {
        available[u] = true;
    }
}

void solve() {
    cin >> n >> k;
    init();
    xor_a = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xor_a = (xor_a ^ a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    if (xor_a == 0) {
        cout << "YES" << '\n';
        return;
    }
    if (k == 2) {
        cout << "NO" << '\n';
        return;
    }
    okay = false;
    dfs(1, 1);
    cout << (okay ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}