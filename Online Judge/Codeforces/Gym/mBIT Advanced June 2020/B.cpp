#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1e3 + 5;

int n;
int h[N];
int dist[N];
vector<int> adj[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    auto compare = [&](pair<int, int>& p, pair<int, int>& q) -> bool {
        auto [x1, y1] = p;
        auto [x2, y2] = q;
        return 1LL * y1 * x2 >= 1LL * y2 * x1;
    };
    for (int i = 1; i < n; i++) {
        pair<int, int> cur = make_pair(INF, -INF);
        for (int j = i + 1; j <= n; j++) {
            pair<int, int> now = make_pair(j - i, h[j] - h[i]);
            if (cur.first == INF || compare(now, cur)) {
                cur = now;
                adj[i].emplace_back(j);
            }
        }
    }
    function<void(int)> bfs = [&](int s) {
        queue<int> q;
        q.emplace(s);
        dist[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = 1 + dist[u];
                    q.emplace(v);
                }
            }
        }
    };
    memset(dist, -1, sizeof(dist));
    bfs(1);
    cout << dist[n] << '\n';
    
    return 0;
}