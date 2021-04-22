#include <bits/stdc++.h>

using namespace std;

const int M = 2e5 + 20;
const int MOD = 1e9 + 7;

string n;
int m;
int dp[M][2];

void solve() {
    cin >> n >> m;
    int ans = 0;
    for (char cc : n) {
        int x = cc - '0';
        ans = (ans + dp[m + x][0]) % MOD;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 2; j++) {
            int k = 10 - j;
            dp[i][j] = 1;
            if (i - k >= 0)
                dp[i][j] = (dp[i - k][0] + dp[i - k][1]) % MOD;
        }
    }

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}