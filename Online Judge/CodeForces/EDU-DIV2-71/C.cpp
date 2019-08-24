#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e17;
int tc, n;
long long a, b;
string s;
long long dp[5][5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b >> s;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i + 1] == '1') {
                    dp[i & 1][1] = inf;
                    dp[i & 1][2] = 2 * a + b;
                } else {
                    dp[i & 1][1] = a + b;
                    dp[i & 1][2] = 2 * a + b;
                }
            } else {
                if (s[i] == '0') {
                    if (i + 1 < n && s[i + 1] == '1') {
                        dp[i & 1][1] = inf;
                        dp[i & 1][2] = min(dp[!(i & 1)][1] + 2 * a + b, dp[!(i & 1)][2] + a + 2 * b);
                    } else {
                        dp[i & 1][1] = min(dp[!(i & 1)][1] + a + b, dp[!(i & 1)][2] + 2 * a + 2 * b);
                        dp[i & 1][2] = min(dp[!(i & 1)][1] + 2 * a + b, dp[!(i & 1)][2] + a + 2 * b);
                    }
                } else if (s[i] == '1') {
                    dp[i & 1][1] = inf;
                    dp[i & 1][2] = dp[!(i & 1)][2] + a + 2 * b;
                }
            }
        }
        n--;
        cout << dp[(n & 1)][1] + b << '\n';
    }


    return 0;
}
