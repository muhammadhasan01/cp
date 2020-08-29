#include <bits/stdc++.h>

using namespace std;

long long d, k, a, b, t;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> k >> a >> b >> t;
    long long ans = (d / k) * (k * a + t) + (d - (d / k) * k) * a;
    if (d % k == 0) ans -= t;
    ans = min(ans, d * b);
    if (d >= k) {
        ans = min(ans, k * a + (d - k) * b);
        if (k * a + t < k * b) {
            long long cur = k * a;
            d -= k;
            cur += (d / k) * (k * a + t) + (d - (d / k) * k) * b;
            ans = min(ans, cur);
        }
    }
    cout << ans << '\n';

    return 0;
}