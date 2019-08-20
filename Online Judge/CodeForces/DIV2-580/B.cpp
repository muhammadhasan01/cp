#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long a[N];
long long dp[N][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[i][1] = abs(1 - a[i]);
            dp[i][2] = abs(-1 - a[i]);
        } else {
            long long c1 = abs(1 - a[i]), c2 = abs(-1 - a[i]);
            dp[i][1] = min(dp[i - 1][1] + c1, dp[i - 1][2] + c2);
            dp[i][2] = min(dp[i - 1][1] + c2, dp[i - 1][2] + c1);
        }
    }
    cout << dp[n][1] << '\n';

    return 0;
}
