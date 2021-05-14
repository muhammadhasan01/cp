#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        vector<tuple<int, int, int, int>> ans;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        int root = 0;
        while ((int) adj[root].size() > 1) {
            ++root;
        }

        function<int(int, int)> dfs = [&](int u, int p) {
            int ch = 0, to = u;
            for (int v : adj[u]) {
                if (v == p) continue;
                int x = dfs(v, u);
                if (x < 0) continue;
                ++ch;
                if (ch == 1) {
                    to = x;
                } else if (ch == 2) {
                    ans.emplace_back(p, u, to, x);
                    to = -1;
                } else {
                    ans.emplace_back(u, v, v, x);
                }
            }
            return to;
        };

        int to = dfs(root, -1);
        cout << ans.size() << '\n';
        for (auto& [x1, y1, x2, y2] : ans) {
            cout << x1 + 1 << ' ' << y1 + 1 << ' ' << to + 1 << ' ' << x2 + 1 << '\n';
            to = y2;
        }
    }

    return 0;
}