#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, s, t;
vector<int> adj[N];
int tin[N], low[N], timer = 0;
bool visited[N];
bool is_cutpoint[N];
bool ans[N];
int par[N];

void dfs(int u, int p = -1) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            par[v] = u;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (tin[u] <= low[v] && p != -1) {
                is_cutpoint[u] = true;;
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        is_cutpoint[u] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int len;
        cin >> len;
        vector<int> v(len);
        for (int j = 0; j < len; j++) {
            cin >> v[j];
            if (j > 0) {
                adj[v[j - 1]].emplace_back(v[j]);
                adj[v[j]].emplace_back(v[j - 1]);
            }
        }
    }
    dfs(s);
    ans[s] = ans[t] = true;
    for (int u = t, min_low = low[u]; u != s; u = par[u]) {
        if (is_cutpoint[u] && tin[u] <= min_low) {
            ans[u] = true;
        }
        min_low = min(min_low, low[u]);
    }
    for (int i = 1; i <= n; i++) {
        cout << !ans[i];
    }
    cout << '\n';

    return 0;
}