#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    int sx, sy;
    cin >> sx >> sy;
    vector<vector<bool>> vis(r, vector<bool>(c));
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    vis[sx][sy] = true;
    int cnt = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cnt = cnt + 1;
        for (int it = 0; it < 4; it++) {
            int cx = x + dx[it];
            int cy = y + dy[it];
            if (cx < 0 || cy < 0 || cx >= r || cy >= c) {
                continue;
            }
            if (vis[cx][cy]) {
                continue;
            }
            if (a[cx][cy] == a[sx][sy]) {
                vis[cx][cy] = true;
                q.emplace(cx, cy);
            }
        }
    }
    cout << 1LL * cnt * (cnt - 1) << '\n';
    
    return 0;
}