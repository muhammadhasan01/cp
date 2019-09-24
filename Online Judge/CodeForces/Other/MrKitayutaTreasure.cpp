#include <bits/stdc++.h>
using namespace std;

const int N = 3e4;
const int inf = -1e9;
int n, d;
int cnt[N + 5];
int dp[N + 5][505];

bool check(int x) {
    return (0 <= x && x <= N);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = d; i <= N; i++) {
        for (int j = 1; j <= 500; j++) {
            dp[i][j] = inf;
        }
    }
    dp[d][250] = cnt[d];
    int ans = dp[d][250];
    for (int i = d; i <= N; i++) {
        for (int j = 1; j <= 500; j++) {
            int k = j + d - 250;
            if (1 <= k - 1 && i + k - 1 <= N) dp[i + k - 1][j - 1] = max(dp[i + k - 1][j - 1], dp[i][j] + cnt[i + k - 1]);
            if (1 <= k && i + k <= N) dp[i + k][j] = max(dp[i + k][j], dp[i][j] + cnt[i + k]);
            if (1 <= k + 1 && i + k + 1 <= N) dp[i + k + 1][j + 1] = max(dp[i + k + 1][j + 1], dp[i][j] + cnt[i + k + 1]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';

    return 0;
}
