#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int K = 16;
const int N = (1 << K) + 5;
const int M = K * K + 5;

int n;
int sum_r, sum_b;
char c[K + 5];
int r[K + 5], b[K + 5];
int dp[N][M];
int cnt_r[N], cnt_b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> r[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        sum_r += r[i];
        sum_b += b[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                cnt_r[i] += c[j] == 'R';
                cnt_b[i] += c[j] == 'B';
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < M; j++) {
            if (dp[i][j] < 0) continue;
            for (int k = 0; k < n; k++) {
                if ((i >> k) & 1) continue;
                int max_r = min(r[k], cnt_r[i]);
                int max_b = min(b[k], cnt_b[i]);
                int& cur = dp[i | (1 << k)][j + max_r];
                cur = max(cur, dp[i][j] + max_b);
            }
        }
    }
    int len = (1 << n) - 1;
    int ans = max(sum_r, sum_b);
    for (int i = 0; i < M; i++) {
        if (dp[len][i] < 0) continue;
        ans = min(ans, max(sum_r - i, sum_b - dp[len][i]));
    }
    cout << ans + n << '\n';

    return 0;
}