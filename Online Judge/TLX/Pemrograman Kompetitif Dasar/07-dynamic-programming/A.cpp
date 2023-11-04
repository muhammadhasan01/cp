#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int K = 5e4 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> dp(K, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = x; j < K; j++) {
            if (dp[j - x] == INF) {
                continue;
            }
            dp[j] = min(dp[j], 1 + dp[j - x]);
        }
    }
    int k;
    cin >> k;
    cout << dp[k] << '\n';
    
    return 0;
}