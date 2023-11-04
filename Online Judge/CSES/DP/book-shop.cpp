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
    vector<int> dp(x + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int price = x; price >= 0; price--) {
            int priceb = price - h[i];
            if (priceb < 0) {
                break;
            }
            if (dp[priceb] == -1) {
                continue;
            }
            dp[price] = max(dp[price], dp[priceb] + s[i]);
        }
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
    
    return 0;
}