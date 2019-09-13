#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n, m;
int p[N];
int dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        double k;
        cin >> p[i] >> k;
    }
    for (int i = 1; i <= n; i++) {
        int j = p[i];
        for (int k = j; k >= 1; k--) {
            dp[j] = max(dp[j], 1 + dp[k]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = max(ans, dp[i]);
    }
    cout << n - ans << '\n';

    return 0;
}
