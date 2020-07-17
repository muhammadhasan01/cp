#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n, k;
int deg[N], sz[N];
int ans;
vector<int> adj[N];

void init() {
    ans = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        deg[i] = sz[i] = 0;
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        init();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            deg[u]++, deg[v]++;
        }
        if (k == 1) {
            cout << n - 1 << '\n';
            continue;
        }
        queue<int> q;
        vector<int> par(n + 1);
        for (int i = 1; i <= n; i++)
            if (deg[i] == 1)
                q.emplace(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (par[v] == u) continue;
                par[u] = v;
                if (++sz[v] == k)
                    ans++, sz[v] = 0;
                if (--deg[v] == 1 && sz[v] == 0)
                    q.emplace(v);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}