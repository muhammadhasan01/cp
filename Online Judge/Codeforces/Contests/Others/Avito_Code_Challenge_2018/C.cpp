#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
vector<int> g[N];
vector<pair<int,int>> ans;
int root = 1;

void dfs(int u, int v) {

    if ((int) g[u].size() == 1 && u != v) {
        ans.push_back({root, u});
        return;
    }

    for (auto e : g[u]) {
        if (e != v) dfs(e, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 2) {
        cout << "Yes" << '\n';
        cout << 1 << '\n';
        cout << 1 << " " << 2 << '\n';
        return 0;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if ((int) g[i].size() > 2) {
            root = i;
            cnt++;
        }
        if (cnt == 2) {
            puts("No");
            return 0;
        }
    }

    dfs(root, root);

    cout << "Yes" << '\n';
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.first << " " << e.second << '\n';
    }


    return 0;
}
