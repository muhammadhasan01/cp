#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    deque<pair<int, int>> dq;
    dq.emplace_front(0, 0);
    dist[0][0] = 0;
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();
        if (x == n - 1 && y == m - 1) {
            cout << dist[n - 1][m - 1] << '\n';
            return 0;
        }
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                int cx = x + dx;
                int cy = y + dy;
                if (cx < 0 || cy < 0 || cx >= n || cy >= m) {
                    continue;
                }
                int d = abs(x - cx) + abs(y - cy);
                if (d > 3) {
                    continue;
                }
                if (dist[cx][cy] != -1) {
                    continue;
                }
                if (d == 1 && grid[cx][cy] == '.') {
                    dist[cx][cy] = dist[x][y];
                    dq.emplace_front(cx, cy);
                } else if (grid[cx][cy] == '#') {
                    dist[cx][cy] = dist[x][y] + 1;
                    dq.emplace_back(cx, cy);
                }
            }
        }
    }
    assert(false);
    
    return 0;
}