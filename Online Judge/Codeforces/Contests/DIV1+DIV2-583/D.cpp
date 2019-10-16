#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> a;
vector<vector<short int>> vis, ok, c1, c2;
int ans = 0;

bool dfs(int x, int y) {
    vis[x][y] = 1;
    if (x == n && y == m) {
        ok[x][y] = 1;
        return true;
    } else if (ok[x][y]) return true;
    bool ret = false;
    if (x + 1 <= n && a[x + 1][y] == '.') {
        if (vis[x + 1][y] == 0 && dfs(x + 1, y)) {
            ok[x][y] = 1;
            ret = true;
        } else if (vis[x + 1][y]) {
            ok[x][y] |= ok[x + 1][y];
        }
    }
    if (y + 1 <= m && a[x][y + 1] == '.') {
        if (vis[x][y + 1] == 0 && dfs(x, y + 1)) {
            ok[x][y] = 1;
            ret = true;
        } else if (vis[x][y + 1]) {
            ok[x][y] |= ok[x][y + 1];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<vector<char>> ta((n + 3), vector<char>(m + 3, '#'));
    vector<vector<short int>> temp((n + 3), vector<short int>(m + 3, false));
    a = ta;
    c1 = c2 = ok = vis = temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1, 1);
    if (ok[n][m] != 1) {
        puts("0");
        return 0;
    }
    ok[1][1] = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            c1[i][j] = (c1[i + 1][j] || c1[i][j - 1] || ok[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            c2[i][j] = (c2[i][j + 1] || c2[i - 1][j] || ok[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (i == n && j == m) continue;
            if (c1[i + 1][j - 1] || c2[i - 1][j + 1]) continue;
            puts("1");
            return 0;
        }
    }
    puts("2");

    return 0;
}
