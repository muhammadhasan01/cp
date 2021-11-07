#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto try_pos = [&](int sx, int sy) {
        int ret = 0;
        vector<bool>> vis(n,  vector<bool>(m));
        queue<tuple<int, int, int>> q;
        q.emplace(a[sx][sy], sx, sy);
        vis[sx][sy] = true;
        while (!q.empty()) {
            auto [p, x, y] = q.front();
            q.pop();
            ret++;
            for (int it = 0; it < K; it++) {
                for (int d = 1; d <= p; d++) {
                    int cx = x + d * dx[it];
                    int cy = y + d * dy[it];
                    if (cx < 0 || cx >= n) {
                        break;
                    }
                    if (cy < 0 || cy >= m) {
                        break;
                    }
                    if (a[cx][cy] == 0) {
                        continue;
                    }
                    if (vis[cx][cy]) {
                        continue;
                    }
                    vis[cx][cy] = true;
                    int nx = max(0, min(n - 1, dx[it] + cx));
                    int ny = max(0, min(m - 1, dy[it] + cy));
                    if (a[nx][ny] > 0 && !vis[nx][ny]) {
                        nx = cx, ny = cy;
                    }
                    q.emplace(a[cx][cy], nx, ny);
                }
            }
        }
        return ret;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                continue;
            }
            ans = max(ans, try_pos(i, j));
        }
    }
    cout << ans << '\n';
    
    return 0;
}