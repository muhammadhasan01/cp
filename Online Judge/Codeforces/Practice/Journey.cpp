#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int inf = 2e9;
int n, m, T;
int deg[N], dp[N][N], par[N][N];
bitset<N> vis;

vector<pair<int,int>> g[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> T;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        deg[v]++;
        g[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = inf;
            par[i][j] = -1;
        }
    }

    queue<int> qq;
    qq.push(1);
    vis[1] = 1;
    while (!qq.empty()) {
        int u = qq.front();
        qq.pop();
        for (auto e : g[u]) {
            int v = e.first;
            if (vis[v] == 0) {
                vis[v] = 1;
                qq.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        for (auto e : g[i]) deg[e.first]--;
    }

    queue<int> q;
    q.push(1);
    dp[1][1] = 0, par[1][1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto e : g[u]) {
            int v = e.first;
            int t = e.second;
            for (int i = 1; i <= n; i++) {
                if (par[u][i] == -1) continue;
                if (dp[u][i] + t <= T && dp[u][i] + t < dp[v][i + 1]) {
                    dp[v][i + 1] = dp[u][i] + t;
                    par[v][i + 1] = u;
                }
            }
            if (--deg[v] == 0) q.push(v);
        }

    }

    for (int i = n; i >= 1; i--) {
        if (dp[n][i] <= T) {
            int len = i;
            int cur = n;
            deque<int> ans;
            while (i > 0) {
                ans.push_front(cur);
                cur = par[cur][i];
                i--;
            }
            cout << len << '\n';
            for (int j = 0; j < len; j++) {
                cout << ans[j] << (j == len - 1 ? '\n' : ' ');
            }
            return 0;
        }
    }

    return 0;
}
