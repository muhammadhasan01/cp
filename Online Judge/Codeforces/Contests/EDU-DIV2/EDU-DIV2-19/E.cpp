#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int S = 325;

int n, q;
int a[N];
int dp[N][S];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j < S; j++) {
            int val = a[i] + i + j;
            dp[i][j] = 1;
            if (val <= n) {
                dp[i][j] += dp[val][j];
            }
        }
    }
    cin >> q;
    while (q--) {
        int p, k;
        cin >> p >> k;
        if (k < S) {
            cout << dp[p][k] << '\n';
        } else {
            int ans = 0;
            while (p <= n) {
                p = p + a[p] + k;
                ++ans;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}