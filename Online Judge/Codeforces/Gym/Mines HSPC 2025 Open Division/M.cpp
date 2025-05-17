#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> h(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
        }
    }
    int x0, y0, xf, yf;
    cin >> x0 >> y0 >> xf >> yf;
    --x0; --y0; --xf; --yf;
    vector<vector<array<int, 2>>> dist(n, vector<array<int, 2>>(m, {INF, INF}));
    deque<tuple<int, int, int>> q;
    for (int p = 0; p < 2; p++) {
        dist[x0][y0][p] = 0;
        q.emplace_back(x0, y0, p);
    }
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
    while (!q.empty()) {
        auto [i, j, p] = q.front();
        q.pop_front();
        int d = dist[i][j][p];
        for (int k = 0; k < 8; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) 
                continue;
            bool canMove = (p == 0) ? (h[ni][nj] < h[i][j]) : (h[ni][nj] > h[i][j]);
            if (!canMove) 
                continue;
            int np = 1 - p;
            if (dist[ni][nj][np] > d + 1) {
                dist[ni][nj][np] = d + 1;
                q.emplace_back(ni, nj, np);
            }
        }
    }
    int ans = min(dist[xf][yf][0], dist[xf][yf][1]);
    cout << (ans < INF ? ans : -1) << '\n';

    return 0;
}
