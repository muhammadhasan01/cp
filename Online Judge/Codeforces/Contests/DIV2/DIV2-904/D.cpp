#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    vector<int> cdiv(n + 1);
    vector<int> cmul(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            cdiv[j] += freq[i];
            cmul[i] += freq[j];
        }
    }
    long long ans = 1LL * n * (n - 1) / 2;
    vector<long long> dp(n + 1);
    for (int i = n; i >= 1; i--) {
        dp[i] = 1LL * cmul[i] * (cmul[i] - 1) / 2;
        for (int j = i + i; j <= n; j += i) {
            dp[i] -= dp[j];
        }
        if (cdiv[i] > 0) {
            if (freq[i] == 0 && dp[i] > 0) {
                cerr << i << "\n";
            }
            ans -= dp[i];
        }
    }
    cout << ans << '\n';
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