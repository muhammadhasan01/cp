#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;
const int K = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> a(n, vector<char>(m));
    pair<int, int> X, O;
    vector<pair<int, int>> tele_pos;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
            if (a[i][j] == 'X') {
                X = make_pair(i, j);
            } else if (a[i][j] == 'O') {
                O = make_pair(i, j);
            } else if (a[i][j] == '*') {
                tele_pos.emplace_back(i, j);
            }
        }
    }
    auto get_dist = [&](int sx, int sy) {
        vector<vector<int>> dist(n, vector<int>(n, INF));
        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        dist[sx][sy] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < K; i++) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if (cx < 0 || cx >= n) {
                    continue;
                }
                if (cy < 0 || cy >= m) {
                    continue;
                }
                if (a[cx][cy] == '#') {
                    continue;
                }
                if (dist[cx][cy] == INF) {
                    dist[cx][cy] = 1 + dist[x][y];
                    q.emplace(cx, cy);
                }
            }
        }
        return dist;
    };
    auto dist_X = get_dist(X.first, X.second);
    auto dist_O = get_dist(O.first, O.second);
    int ans = dist_O[X.first][X.second]; // without teleportation
    {
        // use teleportation
        int nearest = INF;
        for (auto [x, y] : tele_pos) {
            nearest = min(nearest, dist_X[x][y]);
        }
        for (auto [x, y] : tele_pos) {
            if (dist_O[x][y] >= k) {
                ans = min(ans, dist_O[x][y] + nearest + 1);
            } else {
                int dif = k - dist_O[x][y];
                if (dif % 2 == 0) {
                    ans = min(ans, k + nearest + 1);
                } else {
                    ans = min(ans, k + nearest + 1 + 1);
                }
            }
        }
    }
    if (ans >= INF) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}