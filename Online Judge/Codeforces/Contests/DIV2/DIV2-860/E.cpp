#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<bool> correct(n + 2);
    vector<int> dp(n + 2);
    correct[n + 1] = true;
    int maxCorrect = 0;
    for (int i = n; i >= 1; i--) {
        int pos = i + a[i] + 1;
        if (pos <= n + 1 && correct[pos]) {
            correct[i] = true;
            dp[i] = 1 + dp[pos];
            maxCorrect = max(maxCorrect, dp[i]);
            continue;
        }
        if (pos > n) {
            dp[i] = 1 + maxCorrect;
            continue;
        }
        dp[i] = 1 + max(maxCorrect, dp[pos]);
    }
    for (int i = 1; i < n; i++) {
        if (correct[i + 1] && dp[i + 1] == a[i]) {
            cout << 0;
        } else if (correct[i + 1] || a[i] <= dp[i + 1]) {
            cout << 1;
        } else {
            cout << 2;
        }
        cout << " \n"[i == n - 1];
    }
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