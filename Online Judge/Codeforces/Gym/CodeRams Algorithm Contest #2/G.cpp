#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 4e2 + 5;

int n;
int a[N][N];
long long pre[N][N];
long long sum_r[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            ans += a[i][j];
            pre[i][j] = pre[i - 1][j] + a[i][j];
            sum_r[i] += a[i][j];
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = x; y <= n; y++) {
            long long sum = -INF;
            vector<long long> dp(n + 1);
            for (int k = 1; k <= n; k++) {
                long long val = pre[n][k] - (pre[y][k] - pre[x - 1][k]);
                dp[k] = max(val, val + dp[k - 1]);
                sum = max(sum, dp[k]);
            }
            for (int i = x; i <= y; i++) {
                sum += sum_r[i];
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';

    return 0;
}