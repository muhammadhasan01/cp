#include <bits/stdc++.h>

using namespace std;

const int K = 2e7 + 5;
const int N = 8e2 + 5;
const int M = N * N;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n;
bool not_ok[K];
long long pre[M];
char a[N][N];
int col[N][N];
int cnt_col[M];

void dfs(int x, int y, int c) {
    col[x][y] = c;
    cnt_col[c]++;
    for (int it = 0; it < 4; it++) {
        int nx = x + dx[it];
        int ny = y + dy[it];
        if (nx < 1 || nx > n || ny < 1 || ny > n) {
            continue;
        }
        if (a[nx][ny] == 'x') {
            continue;
        }
        if (col[nx][ny] == 0) {
            dfs(nx, ny, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < K; i++) {
        if (not_ok[i]) {
            continue;
        }
        for (int j = i + i; j < K; j += i) {
            not_ok[j] = true;
        }
    }
    int cnt = 0;
    for (int i = 1, j = 1; i < K; i++) {
        if (not_ok[i]) {
            continue;
        }
        pre[j] = pre[j - 1] + i;
        j += 1;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int colors = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 'x' || col[i][j] > 0) {
                continue;
            }
            colors += 1;
            dfs(i, j, colors);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= colors; i++) {
        ans += pre[cnt_col[i]];
    }
    cout << ans << '\n';

    return 0;
}