#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int deg[N];
int ans[N];
vector<int> adj[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
        deg[u]++;
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            pq.emplace(i);
    int cur = n;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans[u] = cur--;
        for (auto v : adj[u]) {
            if (--deg[v] == 0)
                pq.emplace(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}