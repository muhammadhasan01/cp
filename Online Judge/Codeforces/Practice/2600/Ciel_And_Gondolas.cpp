#include <bits/stdc++.h>

using namespace std;

const int N = 4e3 + 5;
const int K = 8e2 + 5;
const int INF = 2e9;

int n, k;
int a[N][N];
int sz[N][N];
int prec[N][N];
int dp[2][N];

int get(int x, int y) {
    return sz[y][y] - sz[x - 1][y] - sz[y][x - 1] + sz[x - 1][x - 1];
}

void compute(int x, int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    int best = INF, opt = optl, y = (x ^ 1);
    for (int i = optl; i <= min(optr, r); i++) {
        if (dp[y][i] + prec[i + 1][mid] <= best) {
            best = dp[y][i] + prec[i + 1][mid];
            opt = i;
        }
    }
    dp[x][mid] = best;
    compute(x, l, mid - 1, optl, opt);
    compute(x, mid + 1, r, opt, optr);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int pre = 0;
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            pre += a[i][j];
            sz[i][j] = pre + sz[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prec[i][j] = get(i, j) / 2;
        }
    }
    memset(dp[0], 63, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        compute((i & 1), 1, n, 0, n);
    }
    cout << dp[(k & 1)][n] << '\n';

    return 0;
}