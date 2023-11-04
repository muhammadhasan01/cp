#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> sz(n + 1);
    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    vector<int> eul(n + 1);
    int tim = 0;

    function<void(int, int)> compute = [&](int u, int p) {
        tin[u] = ++tim;
        eul[tim] = u;
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            compute(v, u);
            sz[u] += sz[v];
        }
        tout[u] = tim;
    };

    compute(1, 1);

    vector<long long> ans(n + 1);
    vector<int> cnt(n + 1);
    long long curSum = 0;
    int maxFreq = 0;

    auto checkColor = [&](int c) -> void {
        if (cnt[c] > maxFreq) {
            maxFreq = cnt[c];
            curSum = c;
        } else if (cnt[c] == maxFreq) {
            curSum += c;
        }
    };

    function<void(int, int, bool)> dfs = [&](int u, int p, bool keep) {
        int mx = -1;
        int bigChild = -1;
        for (int v : adj[u]) {
            if (v != p && sz[v] > mx) {
                mx = sz[v];
                bigChild = v;
            }
        }
        for (int v : adj[u]) {
            if (v != p && v != bigChild) {
                dfs(v, u, false);
            }
        }
        if (bigChild != -1) {
            dfs(bigChild, u, true);
        }
        for (int v : adj[u]) {
            if (v != p && v != bigChild) {
                for (int t = tin[v]; t <= tout[v]; t++) {
                    int node = eul[t];
                    ++cnt[color[node]];
                    checkColor(color[node]);
                }
            }
        }
        ++cnt[color[u]];
        checkColor(color[u]);
        ans[u] = curSum;
        if (!keep) {
            for (int t = tin[u]; t <= tout[u]; t++) {
                int node = eul[t];
                --cnt[color[node]];
            }
            maxFreq = 0;
            curSum = 0;
        }
    };

    dfs(1, 1, 0);
    for (int u = 1; u <= n; u++) {
        cout << ans[u] << " \n"[u == n];
    }
    
    return 0;
}