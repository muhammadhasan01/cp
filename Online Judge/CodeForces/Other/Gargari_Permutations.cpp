#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, k;
vector<int> g[N];
int pos[10][N], sz[N], ans;
bitset<N> vis;

void dfs(int u) {
    vis[u] = 1;
    sz[u]++;
    for (auto v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
        sz[u] = max(sz[u], sz[v] + 1);
    }
    ans = max(ans, sz[u]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int t = 1; t <= k; t++) {
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            pos[t][x] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            bool ok = true;
            for (int t = 1; t <= k; t++) {
                ok &= (pos[t][i] < pos[t][j]);
                if (!ok) break;
            }
            if (ok) {
                g[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    cout << ans << '\n';

    return 0;
}
