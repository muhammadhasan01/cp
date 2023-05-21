#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    cin >> n >> w;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<long long> dp(w + 1);
    for (int i = 0; i < n; i++) {
        vector<long long> ndp(w + 1);
        for (int j = 0; j <= w; j++) {
            ndp[j] = dp[j];
            if (j >= a[i]) {
                ndp[j] = max(ndp[j], dp[j - a[i]] + b[i]);
            }
        }
        ndp.swap(dp);
    }
    cout << dp[w] << '\n';

    return 0;
}