#include <bits/stdc++.h>

using namespace std;

template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Vector dimension must be greater than zero!");
    template<typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) { }
};

template<typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, const T& val = T()) : vector<T>(n, val) { }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    Vec<2, int> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<long long> sz(n + 1);
    vector<long long> dp(n + 1);
    vector<long long> others(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        others[u] = n - 1;
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            sz[u] += sz[v];
            dp[u] += sz[v] * (others[u] - sz[v]);
            others[u] -= sz[v];
        }
    };

    dfs(1, 1);
    long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
    for (int u = 1; u <= n; u++) {
        ans -= dp[u];
    }
    cout << ans << '\n';
    
    return 0;
}