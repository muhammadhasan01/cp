#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};
const pair<int, int> XX = {-1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int ax = -1, ay = -1;
    int bx = -1, by = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                ax = i;
                ay = j;
            } else if (grid[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, XX));

    auto bfs = [&](int sx, int sy) -> void {
        queue<pair<int, int>> q;
        par[sx][sy] = {sx, sy};
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
                if (par[cx][cy] != XX) {
                    continue;
                }
                par[cx][cy] = {x, y};
                q.emplace(cx, cy);
            }
        }
    };

    bfs(ax, ay);

    string ans = "";
    for (int x = bx, y = by; x != ax && y != by; ) {
        if (par[x][y] == XX) {
            cout << "NO" << '\n';
            return 0;
        }
        auto [cx, cy] = par[x][y];
        if (x == cx + 1) {
            ans += "R";
        } else if (x == cx - 1) {
            ans += "L";
        } else if (y == cy + 1) {
            ans += "U";
        } else if (y == cy - 1) {
            ans += "D";
        }
        x = cx, y = cy;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << '\n';
    cout << (int) ans.size() << '\n';
    cout << ans << '\n';
    
    return 0;
}