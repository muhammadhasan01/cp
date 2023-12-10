#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> dp(x + 1);
    for (int i = 0; i < n; i++) {
        vector<int> ndp(x + 1);
        for (int j = 0; j <= x; j++) {
            ndp[j] = dp[j];
            if (j >= h[i]) {
                ndp[j] = max(ndp[j], dp[j - h[i]] + s[i]);
            }
        }
        dp.swap(ndp);
    }
    cout << dp[x] << '\n';
    
    return 0;
}