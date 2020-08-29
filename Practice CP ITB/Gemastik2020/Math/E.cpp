#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long double fastpow(long double x, int y) {
    long double ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x);
        y >>= 1;
        x = (x * x);
    }
    return ret;
}

int n, m;
long double dp[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (long double i = 1; i <= m; i++) {
        dp[(int) i] = fastpow(i / m, n);
    }
    long double ans = 0;
    for (int i = 1; i <= m; i++) {
        long double j = i;
        ans += (dp[i] - dp[i - 1]) * j;
    }
    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}