#include <bits/stdc++.h>
using namespace std;

const int N = 7 + 5;
int n, m;
vector<int> v = {1, 1, 2, 3, 4, 5, 6};
bool vis[10], visp[10][10];
vector<int> g[N];
int ans, res;

void dfs(int u) {
    vis[u] = 1;
    int x = v[u - 1];
    for (auto e : g[u]) {
        int y = v[e - 1];
        int ux = min(x, y), uy = max(x, y);
        if (!visp[ux][uy]) {
            visp[ux][uy] = 1;
            res++;
        }
        if (!vis[e]) {
            dfs(e);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n <= 6) {
        cout << m << '\n';
        return 0;
    }

    do {
        memset(vis, 0, sizeof(vis));
        memset(visp, 0, sizeof(visp));
        res = 0;
        for (int i = 1; i <= 7; i++) {
            if (!vis[i]) dfs(i);
        }
        ans = max(ans, res);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << '\n';

    return 0;
}
