#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int K = 1e3 + 5;
const int M = 1e9 + 7;

int n, k;
int dp[K][N];
int pre[K][N], suf[K][N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i <= k + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            dp[i][j] = pre[i][j] = suf[i][j] = 0;
        }
    }
    int ans = 1;
    for (int j = 0; j <= n + 1; j++)
        pre[k + 1][j] = 1;
    for (int i = k, t = 1; i >= 1; i--, t ^= 1) {
        if (t) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = pre[i + 1][j - 1];
                if (i > 1) ans = (ans + dp[i][j]) % M;
            }
            for (int j = n; j >= 1; j--) {
                suf[i][j] = (suf[i][j + 1] + dp[i][j]) % M;
            }
        } else {
            for (int j = n; j >= 1; j--) {
                dp[i][j] = suf[i + 1][j + 1];
                if (i > 1) ans = (ans + dp[i][j]) % M;
            }
            for (int j = 1; j <= n; j++) {
                pre[i][j] = (pre[i][j - 1] + dp[i][j]) % M;
            }
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}