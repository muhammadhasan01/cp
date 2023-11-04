#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};

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
    vector<vector<bool>> vis(n, vector<bool>(m));

    auto bfs = [&](int sx, int sy) -> void {
        queue<pair<int, int>> q;
        vis[sx][sy] = 1;
        q.emplace(sx, sy);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < K; k++) {
                int cx = x + DX[k];
                int cy = y + DY[k];
                if (cx < 0 || cy < 0 || cx >= n || cy >= m) {
                    continue;
                }
                if (grid[cx][cy] == '#') {
                    continue;
                }
                if (vis[cx][cy]) {
                    continue;
                }
                vis[cx][cy] = 1;
                q.emplace(cx, cy);
            }
        }
    };

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                continue;
            }
            if (vis[i][j]) {
                continue;
            }
            bfs(i, j);
            ++cnt;
        }
    }
    cout << cnt << '\n';
    
    return 0;
}