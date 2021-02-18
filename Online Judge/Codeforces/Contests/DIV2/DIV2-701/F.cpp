#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<long long, int> dp;
    int ans = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int v = (i == 1 ? 1 : (ans - dp[sum] + M) % M);
        ans = (ans + v) % M;
        dp[sum] = (dp[sum] + v) % M;
        sum += x;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}