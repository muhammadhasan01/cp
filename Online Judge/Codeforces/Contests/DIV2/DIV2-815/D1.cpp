#include <bits/stdc++.h>

using namespace std;

const int K = 300;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= max(0, i - K); j--) {
            if ((a[j] ^ i) < (a[i] ^ j)) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
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