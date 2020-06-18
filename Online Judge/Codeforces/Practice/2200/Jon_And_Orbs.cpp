#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const long double eps = 1e-7;
long double dp[N];
int ans[N];
int k, q, d = 1;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> q;
    dp[0] = 1;
    for (int n = 1; d <= 1000; ++n) {
        for (int x = k; x > 0; --x) {
            dp[x] = (x * dp[x] + (k - x + 1) * dp[x - 1]) / k;
        }
        while (d <= 1000 && 2000 * dp[k] >= (d - eps)) {
            ans[d] = n;
            d++;
        }
        dp[0] = 0;
    }
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }

    return 0;
}