#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        deg[v]++;
    }
    vector<int> ans;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == 0) {
            ans.emplace_back(u);
        }
    }
    if ((int) ans.size() != 1) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans[0] << '\n';

    return 0;
}