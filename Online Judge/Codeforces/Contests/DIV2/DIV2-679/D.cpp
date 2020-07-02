#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5; 

int n, m;
bool a[N][N];
bool vis[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void go(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cx > n) continue;
        if (cy < 1 || cy > m) continue;
        if (!a[cx][cy]) continue;
        if (vis[cx][cy]) continue;
        go(cx, cy);
    }
}

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            a[i][j] = (x == '#');
        }
    }
    bool f1 = false;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                if (j > 1 && a[i][j - 1]) continue;
                cnt++;
            }
        }
        if (cnt > 1) dismiss();
        if (cnt == 0) f1 = true; 
    }
    bool f2 = false;
    for (int j = 1; j <= m; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][j]) {
                if (i > 1 && a[i - 1][j]) continue;
                cnt++;
            }
        }
        if (cnt > 1) dismiss();
        if (cnt == 0) f2 = true;
    }
    if (f1 != f2) dismiss();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] && !vis[i][j]) {
                ans++;
                go(i, j);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}