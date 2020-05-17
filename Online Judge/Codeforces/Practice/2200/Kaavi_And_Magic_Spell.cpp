#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;
const int N = 3e3 + 5;

char s[N], t[N];
int dp[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> (s + 1) >> (t + 1);
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    for (int i = m + 1; i <= n + 1; i++) {
        t[i] = '$';
    }
    for (int i = 1; i <= n + 1; i++) {
        dp[i][0] = 1;
    }
    int ans = 0;
    for (int len = 1; len <= n; ++len) {
        char curchar = s[len];
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (t[r] == '$' || t[r] == curchar) {
                dp[l][len] += dp[l][len - 1];
                dp[l][len] %= M;
            }
            if (t[l] == '$' || t[l] == curchar) {
                dp[l][len] += dp[l + 1][len - 1];
                dp[l][len] %= M;
            }
        }
        if (len >= m) {
            ans = (ans + dp[1][len]) % M;
        }
    }
    cout << ans << '\n';

    return 0;
}