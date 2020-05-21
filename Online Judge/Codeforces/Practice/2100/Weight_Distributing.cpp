#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18;

int tc;
int n, m;
int nodez[3];
int dist[3][N];
int p[N];
long long pre[N];
vector<int> g[N];

void bfs(int x) {
    queue<int> q;
    vector<bool> vis(n + 3);
    q.push(nodez[x]);
    dist[x][nodez[x]] = 0;
    vis[nodez[x]] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[x][v] = dist[x][u] + 1;
                q.push(v);
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 0; i < 3; i++) {
            cin >> nodez[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> p[i];
        }
        sort(p + 1, p + 1 + m);
        for (int i = 1; i <= m; i++) {
            pre[i] = (1LL) * p[i] + pre[i - 1];
        }
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 0; i < 3; i++) {
            bfs(i);
        }
        long long ans = INF;
        for (int i = 1; i <= n; i++) {
            int sum = 0, pick = 0;
            for (int j = 0; j < 3; j++) {
                sum += dist[j][i];
                if (j == 1) pick = dist[j][i];
            }
            if (sum > m) continue;
            ans = min(ans, pre[pick] + pre[sum]);
        }
        cout << ans << '\n';
    }

    return 0;
}