#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 6e4 + 5;
const long long MOD = 1e9 + 7;

int tc;
int n, m;
vector<int> adj[N];
long long sz[N];
long long p[M];

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void DP(int u, int p, vector<long long>& parts) {
    for (auto v : adj[u]) {
        if (v == p) continue;
        long long res = (1LL) * (n - sz[v]) * (sz[v]);
        parts.emplace_back(res);
        DP(v, u, parts);
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear(); sz[i] = 0;
    }
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
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    dfs(1, 1);
    vector<long long> parts;
    DP(1, 1, parts);
    sort(p, p + m, greater<long long>());
    sort(parts.begin(), parts.end(), greater<long long>());
    long long ans = 0;
    if (n - 1 < m) {
        int dif = (m - (n - 1));
        for (int i = 1; i <= dif; i++) {
            p[i] = (p[i] * p[i - 1]) % MOD;
        }
        for (int i = dif; i < m; i++) {
            parts[i - dif] %= MOD;
            long long res = (parts[i - dif] * p[i]) % MOD;
            ans = (ans + res) % MOD;
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
            parts[i] %= MOD;
            long long k = (i < m ? p[i] : 1LL) % MOD;
            long long res = (parts[i] * k) % MOD;
            ans = (ans + res) % MOD;
        }
    }
    cout << (ans % MOD + MOD) % MOD << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}