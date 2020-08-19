#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
set<int> adj[N];
int deg[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        swap(u, v);
        if (adj[u].find(v) != adj[u].end()) continue;
        adj[u].emplace(v);
        deg[v]++;
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0)
            pq.emplace(i);
    }
    deque<int> ans;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.emplace_front(u);
        for (auto v : adj[u]) {
            if (--deg[v] == 0)
                pq.emplace(v);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}