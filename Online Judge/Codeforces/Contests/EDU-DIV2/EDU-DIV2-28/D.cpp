#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = N * N;
const int INF = 1e9;

int n, m, k, q;
int tim[N][N];
int dp[N][N];

int get(int p, int q, int r, int s) {
    return dp[r][s] - dp[p - 1][s] - dp[r][q - 1] + dp[p - 1][q - 1];
}

bool can(int curtim) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int pre = 0;
        for (int j = 1; j <= m; j++) {
            pre += (tim[i][j] <= curtim);
            dp[i][j] = dp[i - 1][j] + pre;
        }
    }
    int sz = k * k;
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= m - k + 1; j++) {
            if (get(i, j, i + k - 1, j + k - 1) == sz) {
                return true;
            }
        }
    }
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tim[i][j] = INF + 100;
        }
    }
    for (int i = 1; i <= q; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        tim[x][y] = t;
    }
    int l = 0, r = INF, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}