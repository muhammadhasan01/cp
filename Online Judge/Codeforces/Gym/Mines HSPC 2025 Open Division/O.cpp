#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p;
vector<vector<int>> adj;
vector<int> state;
vector<bool> incycle;
vector<int> dp0, dp1;
vector<int> a_val, b_val;

void dfs(int u, int par) {
    int total = 0;
    for (int v : adj[u]) {
        if (v == par || incycle[v]) {
            continue;
        }
        dfs(v, u);
        total += max(dp0[v], dp1[v]);
    }
    dp0[u] = total;
    int best1 = INT_MIN;
    for (int v : adj[u]) {
        if (v == par || incycle[v]) {
            continue;
        }
        int use_v = total - max(dp0[v], dp1[v]) + dp0[v] + 1;
        best1 = max(best1, use_v);
    }
    dp1[u] = (best1 > INT_MIN ? best1 : 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    p.assign(n + 1, 0);
    adj.assign(n + 1, {});
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != i) {
            adj[i].emplace_back(p[i]);
            adj[p[i]].emplace_back(i);
        }
    }
    for (int u = 1; u <= n; u++) {
        auto &nbrs = adj[u];
        sort(nbrs.begin(), nbrs.end());
        nbrs.erase(unique(nbrs.begin(), nbrs.end()), nbrs.end());
    }
    state.assign(n + 1, 0);
    incycle.assign(n + 1, false);
    vector<vector<int>> cycles;
    for (int i = 1; i <= n; i++) {
        if (state[i] != 0) continue;
        int x = i;
        while (state[x] == 0) {
            state[x] = i;
            x = p[x];
        }
        if (state[x] == i) {
            vector<int> cyc;
            int y = x;
            do {
                cyc.emplace_back(y);
                incycle[y] = true;
                y = p[y];
            } while (y != x);
            cycles.emplace_back(move(cyc));
        }
    }
    dp0.assign(n + 1, 0);
    dp1.assign(n + 1, 0);
    a_val.assign(n + 1, 0);
    b_val.assign(n + 1, 0);
    int tot = 0;
    for (auto &cyc : cycles) {
        int k = (int)cyc.size();
        for (int u : cyc) {
            dfs(u, 0);
        }
        int baseSum = 0;
        vector<int> delta(k, 0);
        for (int i = 0; i < k; i++) {
            int u = cyc[i];
            a_val[u] = dp0[u];
            b_val[u] = max(dp0[u], dp1[u]);
            baseSum += b_val[u];
        }
        for (int i = 0; i < k; i++) {
            int u = cyc[i];
            int v = cyc[(i + 1) % k];
            delta[i] = (a_val[u] - b_val[u]) + (a_val[v] - b_val[v]) + 1;
        }
        vector<int> f1(k + 1, 0);
        f1[0] = 0;
        if (k >= 1) {
            f1[1] = 0;
        }
        for (int i = 2; i <= k; i++) {
            f1[i] = max(f1[i - 1], f1[i - 2] + delta[i - 2]);
        }
        int best1 = f1[k];
        int best2 = INT_MIN;
        if (k > 1) {
            vector<int> f2(k + 1, 0);
            f2[2] = 0;
            for (int i = 3; i <= k - 1; i++) {
                f2[i] = max(f2[i - 1], f2[i - 2] + delta[i - 2]);
            }
            best2 = delta[k - 1] + f2[k - 1];
        }
        int extra = max(best1, best2);
        tot += baseSum + extra;
    }
    int answer = n - 2 * tot;
    cout << answer << "\n";

    return 0;
}