#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<int> dp(n + 1, INF);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), x[i]) - dp.begin();
        dp[pos] = x[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i] == INF) {
            break;
        }
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}