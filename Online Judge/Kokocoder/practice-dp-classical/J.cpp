#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            int pos = i - j;
            if (pos < 0) {
                break;
            }
            dp[i] = min(dp[i], abs(h[i] - h[pos]) + dp[pos]);
        }
    }
    cout << dp[n - 1] << '\n';

    return 0;
}