#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
int n;
int a[N];
int dp[N][N], ans[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            if (j > n) break;
            if (len == 1) {
                dp[i][j] = a[i];
                ans[i][j] = a[i];
            } else {
                dp[i][j] = (dp[i][j - 1] ^ dp[i + 1][j]);
                ans[i][j] = dp[i][j];
                ans[i][j] = max(ans[i][j], ans[i + 1][j]);
                ans[i][j] = max(ans[i][j], ans[i][j - 1]);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ans[l][r] << '\n';
    }

    return 0;
}
