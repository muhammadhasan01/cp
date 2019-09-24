#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 5e3 + 5;
int n, a, b, k;
int dp[N][2];

int mmod(int &a) {
    a = (a % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> k;
    dp[a][1] = 1;
    for (int j = 1; j <= k; j++) {
        int x = (j & 1);
        int y = (x ^ 1);
        for (int i = 1; i <= n; i++) {
            dp[i][y] = 0;
        }
        for (int i = 1; i <= n; i++) {
            long long bef = dp[i][x];
            int dif = abs(i - b);
            dp[max(i - dif + 1, 1)][y] += bef;
            mmod(dp[max(i - dif + 1, 1)][y]);
            dp[min(i + dif, n + 1)][y] -= bef;
            mmod(dp[min(i + dif, n)][y]);
        }
        for (int i cp= 1; i <= n; i++) {
            dp[i][y] += dp[i - 1][y];
            mmod(dp[i][y]);
        }
        for (int i = 1; i <= n; i++) {
            dp[i][y] -= dp[i][x];
            mmod(dp[i][y]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][!(k & 1)];
        mmod(ans);
    }
    cout << ans << '\n';

    return 0;
}
