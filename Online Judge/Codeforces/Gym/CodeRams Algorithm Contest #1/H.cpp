#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 4e2 + 5;

int n;
int a[N][N];
int pre[N][N];

int get_area(int x_1, int y_1, int x_2, int y_2) {
    if (x_1 > x_2 || y_1 > y_2) {
        return 0;
    }
    return pre[x_2][y_2] - pre[x_1 - 1][y_2] - pre[x_2][y_1 - 1] + pre[x_1 - 1][y_1 - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, cur = 0; j <= n; j++) {
            cin >> a[i][j];
            cur += a[i][j];
            pre[i][j] = pre[i - 1][j] + cur;
        }
    }
    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            vector<int> dp(n + 1), x(n + 1), y(n + 1);
            vector<int> sub(n + 1);
            for (int k = 1; k <= n; k++) {
                dp[k] = get_area(i, 1, j, k) - get_area(i + 1, 1 + 1, j - 1, k - 1);
                x[k] = get_area(i, k, j, k);
                y[k] = get_area(i + 1, k, j - 1, k);
                if (k > 1) {
                    sub[k] = max(sub[k - 1], -dp[k] + x[k] + y[k]);
                }
            }
            for (int k = 3; k <= n; k++) {
                ans = max(ans, dp[k] + sub[k - 2]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}