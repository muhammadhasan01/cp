#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<int> dp(n);
    for (int i = 0, j = 0; i < n; i++) {
        while (j + 1 < n && a[i] + k < a[j + 1]) {
            j++;
        }
        if (a[i] + k < a[j]) {
            dp[i] = 1 + dp[j];
        } else {
            dp[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m + k) {
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}