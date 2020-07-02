#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M = 1e9 + 7;
const int N = 1e5 + 3;
ll n, m;
ll dp[N][2], pd[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if (n < m) swap(n, m);
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[i][0] = dp[i][1] = 1;
        } else if (i == 2) {
            dp[i][0] = dp[i][1] = 2;
        } else {
            dp[i][0] = dp[i - 1][1] + dp[i - 2][1];
            dp[i][1] = dp[i - 1][0] + dp[i - 2][0];
        }
        dp[i][0] %= M;
        dp[i][1] %= M;
    }

    ll get = (dp[n][0] + dp[n][1]) % M;
    for (int i = 1; i <= m; i++) {
        if (i == 1) {
            pd[i] = get;
        } else if (i == 2) {
            pd[i] = pd[i - 1] + 2;
        } else {
            pd[i] = pd[i - 1] + (dp[i - 2][0] + dp[i - 2][1]) % M;
        }
        pd[i] %= M;
    }
    cout << (pd[m] % M + M) % M << '\n';

    return 0;
}
