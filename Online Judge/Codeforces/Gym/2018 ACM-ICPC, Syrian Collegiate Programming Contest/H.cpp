#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
int x[N], wv[N];
bool vis[N];
int card[N];
pair<int, int> dest[N];
vector<int> adj[N];
bool is_ok;
long long ans;

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        vis[i] = false;
    }
    ans = 0;
    is_ok = true;
}

void dfs(int i) {
    vis[i] = true;
    auto [u, v] = dest[i];
    int j = -1;
    while (!adj[v].empty()) {
        int cur = adj[v].back();
        adj[v].pop_back();
        if (vis[cur]) {
            continue;
        }
        j = cur;
        break;
    }
    ans += wv[i];
    if (j == -1) {
        if (card[i] != v) {
            is_ok = false;
        }
        return;
    }
    swap(card[i], card[j]);
    dfs(j);
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        wv[i] = abs(x[u] - x[v]);
        dest[i] = make_pair(u, v);
        card[i] = u;
        adj[u].emplace_back(i);
    }
    for (int i = 1; i <= m; i++) {
        if (vis[i]) {
            continue;
        }
        dfs(i);
    }
    if (!is_ok) {
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("bugged.in", "r", stdin);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}