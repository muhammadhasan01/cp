#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    long long d1, d2;
    cin >> n >> d1 >> d2;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] * d2;
    }
    vector<long long> dp = {0, a[0] - d1, -INF};
    for (int i = 1; i < n; i++) {
        vector<long long> ndp(3);
        ndp[0] = max({0LL, dp[0], dp[1], dp[2]});
        ndp[1] = max({dp[0] + a[i] - d1, dp[2] + a[i]});
        ndp[2] = dp[1] + a[i] - d1;
        dp.swap(ndp);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    
    return 0;
}