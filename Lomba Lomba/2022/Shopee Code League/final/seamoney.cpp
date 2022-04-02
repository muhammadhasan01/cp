#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    vector<int> inits;
    {
        int x;
        while (cin >> x) {
            inits.emplace_back(x);
        }
    }
    auto get_ans = [&](int x) -> int {
        vector<bool> vis(n);
        queue<int> q;
        for (int u : inits) {
            if (u == x) {
                continue;
            }
            q.emplace(u);
            vis[u] = 1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; v++) {
                if (vis[v]) {
                    continue;
                }
                if (g[u][v]) {
                    q.emplace(v);
                    vis[v] = 1;
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                ret++;
            }
        }
        return ret;
    };
    pair<int, int> ans = {INT_MAX, -1};
    for (int x : inits) {
        ans = min(ans, make_pair(get_ans(x), x));
    }
    cout << ans.second << '\n';
    
    return 0;
}