#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].emplace_back(i);
    }
    vector<int> depth(n + 1);
    vector<int> ord;
    {
        queue<int> q;
        q.emplace(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ord.emplace_back(u);
            for (int v : adj[u]) {
                depth[v] = 1 + depth[u];
                q.emplace(v);
            }
        }
    }
    
    reverse(ord.begin(), ord.end());
    vector<int> up(n + 1);
    vector<bool> used(n + 1);

    auto can = [&](int h) -> bool {
        fill(up.begin(), up.end(), -1);
        fill(used.begin(), used.end(), false);
        vector<int> st;
        function<void(int)> processUp = [&](int u) {
            st.emplace_back(u);
            int len = st.size();
            if (len - h >= 0) {
                up[u] = st[len - h];
            }
            for (int v : adj[u]) {
                processUp(v);
            }
            st.pop_back();
        };
        processUp(1);
        function<void(int)> dfs = [&](int u) {
            used[u] = true;
            for (int v : adj[u]) {
                if (used[v]) {
                    continue;
                }
                dfs(v);
            }
        };
        int cnt = 0;
        for (int u : ord) {
            if (used[u]) {
                continue;
            }
            if (depth[u] > h) {
                ++cnt;
                if (cnt > k) {
                    return false;
                }
                dfs(up[u]);
            }
        }
        return true;
    };

    int l = 1, r = n - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}