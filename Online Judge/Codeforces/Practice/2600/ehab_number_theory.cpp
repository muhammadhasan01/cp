#include <bits/stdc++.h>

using namespace std;

const int A = 1e6 + 5;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> primes(A);
    vector<int> pp = {1};
    for (int i = 2; i < A; i++) {
        if (primes[i] > 0) {
            continue;
        }
        pp.emplace_back(i);
        for (int j = i; j < A; j += i) {
            primes[j] = i;
        }
    }
    int n;
    cin >> n;
    set<vector<int>> st;
    int ans = INF;
    vector<vector<pair<int, int>>> adj(A);
    auto handle_val = [&](int x, int id) -> void {
        vector<int> pfact;
        while (x > 1) {
            int p = primes[x];
            int c = 0;
            while (x % p == 0) {
                x /= p;
                c ^= 1;
            }
            if (c) {
                pfact.emplace_back(p);
            }
        }
        int len = pfact.size();
        if (len == 0) {
            ans = min(ans, 1);
            return;
        }
        if (len == 1) {
            pfact.emplace_back(1);
        }
        if (st.find(pfact) != st.end()) {
            ans = min(ans, 2);
            return;
        }
        st.emplace(pfact);
        int u = pfact[0];
        int v = pfact[1];
        adj[u].emplace_back(v, id);
        adj[v].emplace_back(u, id);
    };
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        handle_val(x, i);
    }
    if (ans != INF) {
        cout << ans << '\n';
        return 0;
    }
    vector<bool> vis(n);
    vector<int> dist(A);
    for (int s = 1; s * s <= A; s++) {
        fill(vis.begin(), vis.end(), false);
        for (int u : pp) {
            dist[u] = -1;
        }
        queue<int> q;
        dist[s] = 0;
        q.emplace(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& [v, id] : adj[u]) {
                if (vis[id]) {
                    continue;
                }
                vis[id] = 1;
                if (dist[v] == -1) {
                    dist[v] = 1 + dist[u];
                    q.emplace(v);
                } else {
                    ans = min(ans, dist[v] + dist[u] + 1);
                }
            }
        }
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
    
    return 0;
}