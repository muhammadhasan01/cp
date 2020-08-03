#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, m;
int d[N], deg[N], tdeg[N];
set<pair<int, int>> adj[N];
vector<int> ans;
int par[N];
bool vis[N], ok[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

bool merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv)
        return false;
    par[pv] = pu;
    return true;
}

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    bool neg = false;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (d[i] == -1) {
            neg = true;
        } else if (d[i] == 1) {
            ++cnt;
        }
    }
    if (!neg && cnt & 1)
        dismiss();
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    if (neg) {
        int res = cnt & 1;
        for (int i = 1; i <= n; i++) {
            if (d[i] != -1) continue;
            if (res > 0) {
                d[i] = 1;
                res--;
            } else {
                d[i] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (merge(u, v)) {
            adj[u].emplace(v, i);
            adj[v].emplace(u, i);
            deg[u]++, deg[v]++;
            ok[i] = true;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        tdeg[i] = deg[i];
        if (deg[i] == 1) {
            q.emplace(i);
            vis[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& e : adj[u]) {
            int v = e.first;
            int id = e.second;
            if (tdeg[u] % 2 != d[u]) {
                ok[e.second] = 0;
                tdeg[v]--;
            }
            adj[v].erase({u, id});
            if (--deg[v] == 1) {
                q.emplace(v);
                vis[v] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!ok[i]) continue;
        ans.emplace_back(i);
    }
    cout << ans.size() << '\n';
    for (auto& e : ans) {
        cout << e << '\n';
    }

    return 0;
}