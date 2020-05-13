#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;

int n, k;
int a[N], b[N];
bitset<N> dp[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        total += (1LL) * (a[i] + b[i]);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            // leave a[i] % k extra berries
            dp[i][j] = dp[i - 1][(j - a[i] % k + k) % k];
            for (int l = 0; l <= min(k - 1, a[i]); l++) {
                // check if we can leave l extra berries
                if ((a[i] - l) % k + b[i] >= k && dp[i - 1][(j - l + k) % k]) {
                    dp[i][j] = 1;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        if (dp[n][i] == 1) {
            ans = max(ans, (total - i) / k);
        }
    }
    cout << ans << '\n';

    return 0;
}