#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int MAX = 300;
const int K = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<pair<int, int>>> pos(MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            pos[a[i][j]].emplace_back(i, j);
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, INF));
    deque<pair<int, int>> q;
    dist[0][0] = 0;
    q.emplace_front(0, 0);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        // Go to the teleportation first
        if (a[x][y] > 0) {
            for (auto [cx, cy] : pos[a[x][y]]) {
                if (dist[cx][cy] > dist[x][y]) {
                    dist[cx][cy] = dist[x][y];
                    q.emplace_front(cx, cy);
                }
            }
        }
        // Move square
        for (int i = 0; i < K; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m) {
                continue;
            }
            if (dist[cx][cy] > 1 + dist[x][y]) {
                dist[cx][cy] = 1 + dist[x][y];
                q.emplace_back(cx, cy);
            }
        }
    }
    cout << dist[n - 1][m - 1] << '\n';
    
    return 0;
}