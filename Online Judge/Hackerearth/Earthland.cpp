#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int tc;
int n, m;
int assign[N];
bool vis[N];
vector<int> adj[N];

bool matching(int u) {
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (assign[v] == 0 || matching(assign[v])) {
            assign[v] = u;
            return true;
        }
    }
    return false;
}

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        assign[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].emplace_back(u);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            vis[j] = 0;
        if (!matching(i))
            ++ans;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}