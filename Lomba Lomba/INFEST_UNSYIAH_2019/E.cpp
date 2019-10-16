#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
int n, m;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] /= 100;
    }
    m /= 100;

    vector<long long> dp(m + 3, inf);
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - a[j]]);
             }
        }
    }
    cout << dp[m] << '\n';

    return 0;
}
