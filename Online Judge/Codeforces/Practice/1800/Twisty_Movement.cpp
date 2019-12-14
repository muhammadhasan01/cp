#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n;
int a[N];
int pre[N], suf[N];
int dp[N][N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += (a[i] == 1) + pre[i - 1];
    }
    for (int i = n; i >= 0; i--) {
        suf[i] += (a[i] == 2) + suf[i + 1];
        ans = max(ans, pre[i] + suf[i + 1]);
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if (j > n) break;
            if (len == 1) {
                dp[i][j] = 1;
            } else if (len == 2) {
                dp[i][j] = (a[i] == 2 || a[j] == 1 ? 2 : 1);
            } else if (a[i] == 2 && a[j] == 1) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            } else if (a[i] == 2 && a[j] == 2) {
                int cur = suf[i] - suf[j + 1];
                dp[i][j] = max(cur, 1 + dp[i + 1][j - 1]);
            } else if (a[i] == 1 && a[j] == 1) {
                int cur = pre[j] - pre[i - 1];
                dp[i][j] = max(cur, 1 + dp[i + 1][j - 1]);
            } else if (a[i] == 1 && a[j] == 2) {
                int cur = pre[j] - pre[i - 1];
                int ruc = suf[i] - suf[j + 1];
                dp[i][j] = max(dp[i + 1][j - 1], max(cur, ruc));
            }
            ans = max(ans, pre[i - 1] + dp[i][j] + suf[j + 1]);
        }
    }
    cout << ans << '\n';

    return 0;
}
