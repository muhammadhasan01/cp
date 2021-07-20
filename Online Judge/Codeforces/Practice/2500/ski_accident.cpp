#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
vector<int> adj[N];
int tracks[N];

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        tracks[i] = 0;
    }
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    vector<int> ans;
    for (int u = 1; u <= n; u++) {
        if (tracks[u] < 2) {
            for (int v : adj[u]) {
                if (tracks[v] == 2)
                    continue;
                tracks[v] = 1 + tracks[u];
            }
        } else {
            ans.emplace_back(u);
        }
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
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