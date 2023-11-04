#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<long long> dp(2);
    for (int i = 1; i < n; i++) {
        vector<long long> ndp(2);
        ndp[0] = abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]) + dp[0];
        ndp[0] = min(ndp[0], abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]) + dp[1]);
        ndp[1] = abs(b[i] - a[i - 1]) + abs(a[i] - b[i - 1]) + dp[0];
        ndp[1] = min(ndp[1], abs(b[i] - b[i - 1]) + abs(a[i] - a[i - 1]) + dp[1]);
        dp.swap(ndp);
    }
    cout << min(dp[0], dp[1]) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}