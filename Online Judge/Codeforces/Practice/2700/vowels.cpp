#include <bits/stdc++.h>

using namespace std;

const int K = 24;

void solve() {
    int n;
    cin >> n;
    vector<long long> dp(1 << K);
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        int x = (1 << int(a - 'a'));
        int y = (1 << int(b - 'a'));
        int z = (1 << int(c - 'a'));
        dp[x]++;
        dp[y]++;
        dp[z]++;
        dp[x | y]--;
        dp[y | z]--;
        dp[x | z]--;
        dp[x | y | z]++;
    }
    for (int i = 0; i < K; i++) {
        for (int mask = 0; mask < (1 << K); mask++) {
            bool b = mask & (1 << i);
            if (b) {
                int bmask = mask ^ (1 << i);
                dp[mask] += dp[bmask];
            }
        }
    }
    long long ans = 0;
    for (int mask = 0; mask < (1 << K); mask++) {
        ans ^= (dp[mask] * dp[mask]);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}