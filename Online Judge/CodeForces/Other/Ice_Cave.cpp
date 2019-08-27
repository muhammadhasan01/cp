#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m, r1, c1, r2, c2;
char a[N][N];
short int vis[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'X') vis[i][j] = 1;
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;

    bool ok = false;
    queue<pair<int,int>> q;
    q.push({r1, c1});

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,-1,1};

    while (!q.empty()) {
        int x1 = q.front().first, y1 = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];
            if (nx > n || nx < 1) continue;
            if (ny > m || ny < 1) continue;
            if (nx == r2 && ny == c2 && vis[r2][c2] == 1) {
                puts("YES");
                return 0;
            } else if (vis[nx][ny] == 1) {
                continue;
            } else if (vis[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    puts("NO");

    return 0;
}
