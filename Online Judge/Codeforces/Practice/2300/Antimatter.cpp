#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int S = 1e4 + 5;
const int M = 1e9 + 7;

int n;
int a[N];
int dp[N][2 * S];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    dp[0][S] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2 * S; j++) {
            if (j - a[i] >= 0) {
                dp[i][j - a[i]] = (dp[i][j - a[i]] + dp[i - 1][j]) % M;
            }
            if (j + a[i] < 2 * S) {
                dp[i][j + a[i]] = (dp[i][j + a[i]] + dp[i - 1][j]) % M;
            }
        }
        ans = (ans + dp[i][S]) % M;
        dp[i][S]++;
    }
    cout << ans << '\n';

    return 0;
}