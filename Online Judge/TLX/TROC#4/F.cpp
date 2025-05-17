#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> divisors[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }

    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    int mx = *max_element(w.begin(), w.end());
    vector<vector<int>> g(mx + 1);
    for (int i = 1; i <= n; i++) {
        for (int d : divisors[w[i]]) {
            g[d].emplace_back(i);
        }
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int qr;
    cin >> qr;
    vector<vector<tuple<int, int, int>>> queries(mx + 1);
    for (int i = 1; i <= qr; i++) {
        int a, b;
        cin >> a >> b;
        int gcd = __gcd(w[a], w[b]);
        queries[gcd].emplace_back(i, a, b);
    }
    int colors = 0;
    vector<int> col(n + 1);
    vector<int> ans(qr + 1);
    for (int x = 1; x <= mx; x++) {
        queue<int> q;
        int before = colors;
        for (int node : g[x]) {
            if (col[node] <= before) {
                col[node] = ++colors;
                q.emplace(node);
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (col[v] != colors && w[v] % x == 0) {
                        col[v] = colors;
                        q.emplace(v);
                    }
                }
            }
        }
        for (int y = x; y <= mx; y += x) {
            for (auto [i, a, b] : queries[y]) {
                if (col[a] == col[b]) {
                    ans[i] = x;
                }
            }
        }
    }
    for (int i = 1; i <= qr; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}