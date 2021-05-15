#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

const long long INF = 1e18;
const int N = 2e3 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, d;
int a[N][N];
long long mini[2];
long long dp[N][N][2];

void BFS(int x, int y, int z) {
    queue<tuple<int, int, long long>> q;
    dp[x][y][z] = 0LL;
    q.emplace(x, y, dp[x][y][z]);
    while (!q.empty()) {
        auto [u, v, w] = q.front();
        q.pop();
        if (a[u][v] > 0) {
            mini[z] = min(mini[z], dp[u][v][z] + a[u][v]);
        }
        for (int i = 0; i < 4; i++) {
            int cu = u + dx[i];
            int cv = v + dy[i];
            if (cu < 1 || cu > n || cv < 1 || cv > m) continue;
            if (a[cu][cv] == -1) continue;
            if (dp[cu][cv][z] != INF) continue;
            dp[cu][cv][z] = w + d;
            q.emplace(cu, cv, dp[cu][cv][z]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    in(n), in(m), in(d);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            in(a[i][j]);
        }
    }
    for (int it = 0; it < 2; it++) {
        mini[it] = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j][it] = INF;
            }
        }
    }
    long long ans = INF;
    BFS(1, 1, 0);
    ans = min(ans, dp[n][m][0]);
    BFS(n, m, 1);
    ans = min(ans, mini[0] + mini[1]);
    if (ans == INF) ans = -1;
    out(ans, '\n');

    return 0;
}