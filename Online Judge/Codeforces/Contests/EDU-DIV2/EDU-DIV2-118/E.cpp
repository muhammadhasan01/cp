#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    pair<int, int> L;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'L') {
                L = make_pair(i, j);
            }
        }
    }
    auto check = [&](int x, int y) -> bool {
        if (a[x][y] != '.') {
            return false;
        }
        int cnt = 0;
        for (int it = 0; it < K; it++) {
            int cx = x + dx[it];
            int cy = y + dy[it];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m) {
                continue;
            }
            if (a[cx][cy] == '.') {
                ++cnt;
            }
        }
        return cnt <= 1;
    };
    auto [sx, sy] = L;
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int it = 0; it < K; it++) {
            int cx = x + dx[it];
            int cy = y + dy[it];
            if (cx < 0 || cx >= n || cy < 0 || cy >= m) {
                continue;
            }
            if (check(cx, cy)) {
                a[cx][cy] = '+';
                q.emplace(cx, cy);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
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