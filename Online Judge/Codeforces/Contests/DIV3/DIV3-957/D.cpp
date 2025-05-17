#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<char> a(n + 1);
    a[0] = 'L';
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n + 2, INF);
    dp[n + 1] = 0;
    for (int i = n; i >= 0; i--) {
        if (a[i] == 'C') {
            continue;
        }
        int range = (a[i] == 'L' ? m : 1);
        int mn = INF;
        for (int j = i + 1; j <= min(n + 1, i + range); j++) {
            mn = min(mn, dp[j]);
        }
        if (mn == INF) {
            continue;
        }
        dp[i] = (a[i] == 'L' ? mn : 1 + mn);
    }
    cout << (dp[0] <= k ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}