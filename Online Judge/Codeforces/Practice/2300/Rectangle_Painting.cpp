#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int M = N * N;

int n;
char a[N][N];
int dp[M][M];

int getIdx(int x, int y) {
    return (x - 1) * n + y;
}

int getDP(int x_1, int y_1, int x_2, int y_2) {
    if (x_1 == x_2 && y_1 == y_2) return (a[x_1][y_1] == '#');
    int ret = max(x_2 - x_1 + 1, y_2 - y_1 + 1);
    for (int x = x_1; x < x_2; x++) {
        ret = min(ret, dp[getIdx(x_1, y_1)][getIdx(x, y_2)] + dp[getIdx(x + 1, y_1)][getIdx(x_2, y_2)]);
    }
    for (int y = y_1; y < y_2; y++) {
        ret = min(ret, dp[getIdx(x_1, y_1)][getIdx(x_2, y)] + dp[getIdx(x_1, y + 1)][getIdx(x_2, y_2)]);
    }
    return ret;
}

void DP(int row) {
    for (int sz = 1; sz <= row; sz++) {
        int pos = row - sz + 1;
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                dp[getIdx(pos, i)][getIdx(row, i + len - 1)] = getDP(pos, i, row, i + len - 1);
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int row = 1; row <= n; row++) DP(row);
    cout << dp[getIdx(1, 1)][getIdx(n, n)] << '\n';

    return 0;
}