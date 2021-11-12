#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(2, vector<char>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> vis(2, vector<bool>(n));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    vis[0][0] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx < 0 || cy < 0 || cx >= 2 || cy >= n) {
                continue;
            }
            if (a[cx][cy] == '1') {
                continue;
            }
            if (vis[cx][cy]) {
                continue;
            }
            vis[cx][cy] = 1;
            q.emplace(cx, cy);
        }
    }
    cout << (vis[1][n - 1] ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}