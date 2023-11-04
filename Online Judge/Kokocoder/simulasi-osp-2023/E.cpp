#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        if (v == 0) {
            continue;
        }
        adj[u].emplace_back(v);
        deg[v]++;
    }
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 0) {
            q.emplace(u);
        }
    }
    long long ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans += s[u];
        for (int v : adj[u]) {
            s[v] += max(0LL, s[u]);
            if (--deg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}