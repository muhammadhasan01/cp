#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int p;
    cin >> p;
    vector<int> dp(p + 1, INT_MAX);
    dp[0] = 0;
    for (int u = 2; u * (u - 1) / 2 <= p; u++) {
        int v = u * (u - 1) / 2;
        for (int i = v; i <= p; i++) {
            dp[i] = min(dp[i], dp[i - v] + u);
        }
    }
    long long nodes = dp[p];
    long long num = nodes * (nodes - 1) / 2 - p;
    cout << nodes << ' ' << num << '\n';
    
    return 0;
}