#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = 1e9 + 7;

int n, m;
char a[N][N];
int dp[2][N][N];

template<typename T>
inline void add(T& x, T y) {
    x = (x + y) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int len = (n + m) / 2;
    int ans = 0;
    dp[0][0][n] = 1;
    for (int i = 1; i <= len; i++) {
        int now = (i & 1);
        int bfr = 1 - now;
        memset(dp[now], 0, sizeof(dp[now]));
        for (int sx = 1; sx <= n; sx++) {
            for (int ex = sx; ex <= n; ex++) {
                int sy = i + 1 - sx;
                int ey = m - (i + 1 - (n - ex + 1)) + 1;
                if (sy <= 0 || sy > ey || ey > m) {
                    continue;
                }
                if (a[sx][sy] == a[ex][ey]) {
                    for (int dx : {0, -1}) {
                        for (int dy : {0, 1}) {
                            add(dp[now][sx][ex], dp[bfr][sx + dx][ex + dy]);
                        }
                    }
                }
                if (i == len) {
                    add(ans, dp[now][sx][ex]);
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}