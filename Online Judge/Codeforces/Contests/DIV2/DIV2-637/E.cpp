#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int G = 1e3 + 5;
const long long INF = 1e16;

int n, m;
int g, r;
int d[N];

int dist[N][G];
bool vis[N][G];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> d[i];
    }
    sort(d + 1, d + 1 + m);
    cin >> g >> r;
    deque<pair<int, int>> dq;
    dq.push_front({1, d[1]});
    vis[1][d[1]] = 1;
    long long ans = INF;
    while (!dq.empty()) {
        int u = dq.front().first;
        int t = dq.front().second;
        dq.pop_front();
        if (t == 0 && d[u] + g >= n) {
            long long cur = (1LL) * (g + r) * dist[u][t] + (1LL) * (n - d[u]);
            ans = min(ans, cur);
        }
        if (t == g) {
            if (!vis[u][0]) {
                vis[u][0] = 1;
                dist[u][0] = dist[u][t] + 1;
                dq.push_back({u, 0});
            }
            continue;
        }
        if (u > 1) {
            int cur = t + d[u] - d[u - 1];
            if (cur <= g && !vis[u - 1][cur]) {
                vis[u - 1][cur] = 1;
                dist[u - 1][cur] = dist[u][t];
                dq.push_front({u - 1, cur});
            }
        }
        if (u < m) {
            int cur = t + d[u + 1] - d[u];
            if (cur <= g && !vis[u + 1][cur]) {
                vis[u + 1][cur] = 1;
                dist[u + 1][cur] = dist[u][t];
                dq.push_front({u + 1, cur});
            }
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;
}