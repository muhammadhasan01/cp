// WA :(
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 10;

int n, m, k;
vector<pair<int, int>> adj[N];
vector<int> vertex[K];
bitset<N> vis, siv;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
        int len = adj[i].size();
        vertex[len].emplace_back(i);
    }
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        int cnt = 0, ok = -1;
        for (int j = 0; j < i; j++) {
            bool flag = true;
            for (int u = 1; u <= n; u++) {
                siv[u] = vis[u];
            }
            for (auto& u : vertex[i]) {
                int v = adj[u][j].second;
                if (siv[v] == 1) {
                    flag = false;
                    break;
                }
                siv[v] = 1;
            }
            if (flag) {
                ok = j; ++cnt;
            }
        }
        if (ok == -1) {
            cout << 0 << '\n';
            return 0;
        }
        ans *= cnt;
        for (auto& u : vertex[i]) {
            int v = adj[u][ok].second;
            vis[v] = 1;
        }
    }
    cout << ans << '\n';

    return 0;
}