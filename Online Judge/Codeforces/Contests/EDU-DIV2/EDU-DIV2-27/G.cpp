#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = 30;

int n, m;
vector<pair<int, int>> g[N];
bitset<N> vis;
int d[N];
int base[K + 5];

void add(int x) {
    for (int i = K; i >= 0; i--) {
        bool bit = (x & (1 << i));
        if (bit) {
            if (base[i] == 0) {
                base[i] = x;
                return;
            } else {
                x = (x ^ base[i]);
            }
        }
    }
}

void dfs(int u) {
    vis[u] = 1;
    for (auto e : g[u]) {
        int v = e.first;
        int w = e.second;
        if (vis[v]) {
            int cur = (d[v] ^ w ^ d[u]);
            add(cur);
        } else {
            d[v] = (d[u] ^ w);
            dfs(v);
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs(1);
    int ans = d[n];
    for (int i = K; i >= 0; i--) {
        ans = min(ans, (ans ^ base[i]));
    }
    cout << ans << '\n';

    return 0;
}