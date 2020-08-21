#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
int assign[N];
bool vis[N];
vector<int> adj[N];

bool match(int u) {
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (assign[v] == 0 || match(assign[v])) {
            assign[v] = u;
            return true;
        }
    }
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            adj[i].emplace_back(++x);
        }
    }
    int res = n;
    for (int i = 1; i <= n; i++) {
        fill(vis + 1, vis + 1 + n, false);
        if (match(i)) {
            --res;
        }
    }
    cout << res << '\n';

    return 0;
}