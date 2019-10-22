#include <bits/stdc++.h>

using namespace std;

int n, c;
const int N = 2e5 + 3;
const long long inf = 1e18;
long long  dp[2][3];
long long a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> b[i];
    }
    long long cur = 0;
    for (int it = 0; it <= n - 1; it++) {
        int i = (it & 1);
        dp[i][1] = dp[i][2] = inf;
        if (it == 0) {
            dp[i][1] = 0;
            dp[i][2] = c;
        } else {
            dp[i][1] = min(dp[i][1], dp[(i ^ 1)][1] + a[it]);
            dp[i][1] = min(dp[i][1], dp[(i ^ 1)][2] + a[it]);
            dp[i][2] = min(dp[i][2], dp[(i ^ 1)][1] + c + b[it]);
            dp[i][2] = min(dp[i][2], dp[(i ^ 1)][2] + b[it]);
        }
        cout << min(dp[i][1], dp[i][2]) << (i == n ? '\n' : ' ');
    }

    return 0;
}
