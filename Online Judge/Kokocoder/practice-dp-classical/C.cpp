#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j : {1, 2}) {
            int k = i - j;
            if (k < 0) {
                break;
            }
            dp[i] = min(dp[i], abs(h[i] - h[k]) + dp[k]);
        }
    }
    cout << dp[n - 1] << '\n';

    return 0;
}