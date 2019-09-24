#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const ll inf = 1e18;
int n, m, k;
vector<pair<int,int>> g[N];
short int p[N];
bitset<N> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }

    vector<ll> dist(n + 3, inf);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;

    dist[1] = 0;
    q.push({dist[1], 1});

    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        if (dist[x] > y) {
            dist[x] = y;
            p[x] = 1;
            q.push({dist[x], x});
        }
    }

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (vis[u]) continue;

        vis[u] = true;

        for (auto e : g[u]) {
            int v = e.first;
            ll t = e.second;
            if (p[v] && dist[v] >= dist[u] + t) {
                p[v] = 0;
            }
            if (!vis[v] && dist[v] > dist[u] + t) {
                dist[v] = dist[u] + t;
            }
            q.push({dist[v], v});
        }
    }

    int ans = k;
    for (int i = 1; i <= n; i++) {
        if (p[i]) ans--;
    }

    cout << ans << '\n';

    return 0;
}
