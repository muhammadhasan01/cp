#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> tag(n);
    for (int i = 0; i < n; i++) {
        cin >> tag[i];
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<long long> dp(n);
    for (int j = 1; j < n; j++) {
        for (int i = j - 1; i >= 0; i--) {
            if (tag[i] == tag[j]) {
                continue;
            }
            long long dpi = dp[i];
            long long dpj = dp[j];
            long long dif = abs(s[i] - s[j]);
            dp[i] = max(dp[i], dpj + dif);
            dp[j] = max(dp[j], dpi + dif);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
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