#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int inf = 1e9;
int n;
int a[N];
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int len = 0; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len;
            if (j > n) break;
            if (len == 0) {
                dp[i][j] = 1;
            } else if (len == 1) {
                dp[i][j] = (a[i] == a[j] ? 1 : 2);
            } else {
                dp[i][j] = inf;
                if (a[i] == a[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                for (int k = i; k <= j - 1; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }
    cout << dp[1][n] << '\n';


    return 0;
}
