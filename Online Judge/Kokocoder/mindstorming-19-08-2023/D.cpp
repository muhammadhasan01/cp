#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
int s[N];
int dp[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    if (s[j] < s[i]) dp[i] = max(dp[i], 1 + dp[j]);
                    int k = i / j;
                    if (s[k] < s[i]) dp[i] = max(dp[i], 1 + dp[k]);
                }
            }
        }
        cout << *max_element(dp + 1, dp + 1 + n) << '\n';
    }

    return 0;
}