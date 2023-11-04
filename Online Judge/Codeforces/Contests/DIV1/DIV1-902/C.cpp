#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++) {
        deg[a[i]]++;
    }
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 0) {
            q.emplace(u);
        }
    }
    vector<bool> vis(n + 1);
    vector<bool> dead(n + 1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = a[u];
        vis[u] = vis[v] = true;
        if (!dead[v]) {
            dead[v] = true;
            if (--deg[a[v]] == 0) {
                q.emplace(a[v]);
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        if (vis[u]) {
            continue;
        }
        int cycleSize = 0;
        while (!vis[u]) {
            ++cycleSize;
            vis[u] = true;
            if (cycleSize % 2 == 0) {
                dead[u] = true;
            }
            u = a[u];
        }
    }
    vector<int> pos;
    for (int u = 1; u <= n; u++) {
        if (!dead[u]) {
            pos.emplace_back(u);
        }
    }
    vector<bool> circled(n + 1);
    vector<int> ans;
    for (int p : pos) {
        ans.emplace_back(a[p]);
        circled[a[p]] = true;
    }
    int len = (int) ans.size();
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (circled[i]) {
            continue;
        }
        if (idx >= len || ans[idx] != a[i]) {
            cout << -1 << '\n';
            return;
        }
        idx++;
    }
    if (idx != len) {
        cout << -1 << '\n';
        return;
    }
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}