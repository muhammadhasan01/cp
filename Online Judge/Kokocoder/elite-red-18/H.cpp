#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int col[N];
int cnt_one;
vector<int> adj[N];

void init() {
    cnt_one = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        col[i] = -1;
    }
}

void dfs(int u, int p, int c) {
    col[u] = c;
    if (c) {
        cnt_one++;
    }
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u, 1 - c);
    }
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
    vector<int> ans(n + 1);
    dfs(1, 1, 0);
    if (2 * cnt_one > n) {
        for (int i = 1; i <= n; i++) {
            col[i] = 1 - col[i];
        }
    }
    int cur = 1;
    {
        vector<pair<int, int>> nodes;
        for (int i = 1; i <= n; i++) {
            if (col[i]) {
                nodes.emplace_back((int) adj[i].size(), i);
            }
        }
        sort(nodes.rbegin(), nodes.rend());
        for (auto [c, i] : nodes) {
            ans[i] = cur++;
        }
    }
    int last = cur - 1;
    {
        vector<pair<int, int>> nodes;
        for (int i = 1; i <= n; i++) {
            if (col[i]) {
                continue;
            }
            int cnt = 0;
            for (int j : adj[i]) {
                int x = ans[j];
                if ((x ^ last) <= min(x, last)) {
                    ++cnt;
                }
            }
            nodes.emplace_back(cnt, i);
        }
        sort(nodes.rbegin(), nodes.rend());
        cur = n;
        for (auto [c, i] : nodes) {
            ans[i] = cur--;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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