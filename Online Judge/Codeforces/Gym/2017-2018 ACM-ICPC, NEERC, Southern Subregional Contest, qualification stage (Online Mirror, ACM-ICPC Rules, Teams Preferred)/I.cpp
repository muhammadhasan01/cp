#include <bits/stdc++.h>

using namespace std;

const int N = 255;
const int K = 30;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Sound {
    int x, y, sound;
    Sound(int x, int y, int s) : x(x), y(y), sound(s) { }
};

int n, m, q, p;
int res[N][N];
bool vis[N][N];
char a[N][N];

void bfs(int x, int y) {
    queue<Sound> Q;
    int curSound = q * ((int) (a[x][y] - 'A') + 1);
    for (int i = max(1, x - K); i <= min(n, x + K); i++) {
        for (int j = max(1, y - K); j <= min(m, y + K); j++) {
            vis[i][j] = 0;
        }
    }
    vis[x][y] = 1;
    res[x][y] = min(p + 1, res[x][y] + curSound);
    if (curSound / 2 == 0) return;
    Q.emplace(x, y, curSound / 2);
    while (!Q.empty()) {
        Sound tmp = Q.front();
        Q.pop();
        int new_sound = tmp.sound / 2;
        for (int i = 0; i < 4; i++) {
            int cx = tmp.x + dx[i];
            int cy = tmp.y + dy[i];
            if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
            if (a[cx][cy] == '*') continue;
            if (vis[cx][cy]) continue;
            vis[cx][cy] = 1;
            res[cx][cy] = min(p + 1, res[cx][cy] + tmp.sound);
            if (new_sound == 0) continue;
            Q.emplace(cx, cy, new_sound);
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ('A' <= a[i][j] && a[i][j] <= 'Z') {
                bfs(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (res[i][j] > p) ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}