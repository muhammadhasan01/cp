#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n + 1, {0, n + 1});
    vector<pair<int, int>> edges(m);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
        adj[u].emplace(v);
        adj[v].emplace(u);
    }
    long long ans = 0;
    for (int u = 1; u <= n; u++) {
        auto it = adj[u].lower_bound(u);
        int L = *prev(it) + 1;
        int R = *it - 1;
        ans += 1LL * (u - L + 1) * (R - u + 1);
    }
    for (auto [u, v] : edges) {
        if (u > v) {
            swap(u, v);
        }
        if (*adj[u].upper_bound(u) < v || *adj[v].upper_bound(u) < v) {
            continue;
        }
        int L = max(*prev(adj[u].lower_bound(u)), *prev(adj[v].lower_bound(u))) + 1;
        int R = min(*adj[u].upper_bound(v), *adj[v].upper_bound(v)) - 1;
        ans += 2LL * (u - L + 1) * (R - v + 1);
    }
    cout << ans << '\n';

    return 0;
}