#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
vector<int> adj[N];
int color[N];

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        color[i] = 0;
    }
}

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void solve() {
    cin >> n;
    init();
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++) {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++) {
            int x;
            cin >> x;
            adj[x].emplace_back(i);
            deg[i]++;
        }
    }
    for (int u = 1; u <= n; u++) {
        if (color[u] == 0 && dfs(u)) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<int> days(n + 1);
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 0) {
            days[u] = 1;
            q.emplace(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (u > v) {
                days[v] = max(days[v], days[u] + 1);
            } else {
                days[v] = max(days[v], days[u]);
            }
            if (--deg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    cout << *max_element(days.begin(), days.end()) << '\n';
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