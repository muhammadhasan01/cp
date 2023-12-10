#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    auto getVal = [&](int i) -> long long {
        return max(h[i], max(h[i - 1], h[i + 1]) + 1) - h[i];
    };

    if (n & 1) {
        long long ans = 0;
        for (int i = 1; i + 1 < n; i += 2) {
            ans += getVal(i);
        }
        cout << ans << '\n';
        return;
    }
    vector<long long> dp(K);
    for (int i = 1; i + 1 < n; i += 2) {
        vector<long long> ndp(K);
        long long x = getVal(i);
        long long y = getVal(i + 1);
        ndp[0] = x + dp[0];
        ndp[1] = y + min(dp[0], dp[1]);
        dp.swap(ndp);
    }
    cout << min(dp[0], dp[1]) << '\n';
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