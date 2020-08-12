#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, q, k;
char a[N][N];
int dist[N][N];

void bfs(int X, int Y) {
    queue<pair<int, int>> q;
    q.emplace(X, Y);
    dist[X][Y] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x < 0 || x > n || y < 0 || y > m) continue;
            if (a[x][y] == 'X') continue;
            if (dist[x][y] <= 1 + dist[cur.first][cur.second]) continue;
            dist[x][y] = 1 + dist[cur.first][cur.second];
            q.emplace(x, y);
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dist[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != 'X') continue;
            bfs(i, j);
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << dist[x][y] << '\n';
    }

    return 0;
}