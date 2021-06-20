#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int ans;
vector<int> adj[N];

void init() {
    ans = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
}

int dfs(int u, int p) {
    if ((int) adj[u].size() == 1 && u != 1) {
        return 1;
    }
    vector<int> cur;
    for (int v : adj[u]) {
        if (v == p) continue;
        cur.emplace_back(dfs(v, u));
    }
    sort(cur.begin(), cur.end());
    int len = cur.size();
    if (len > 1) {
        if (u == 1) {
            ans = max({ans, cur[len - 1], cur[len - 2] + 1});
        } else {
            ans = max(ans, cur[len - 1] + 1);
        }
    }
    ans = max(ans, cur[0]);
    return cur[0] + 1;
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 0);
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}