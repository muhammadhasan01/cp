#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n, s, t, a, b;
    cin >> n >> s >> t >> a >> b;
    long double ans = 2e18;
    if (t >= s) {
        ans = min(ans, (long double) a * (t - s));
    } 

    auto F = [&](long double x) -> long double {
        return (x - 1) * a / 2.0 + (long double) b * ((long double) n / x);
    };
    
    int l = 1, r = t;
    while (l <= r) {
        int mid = (l + r) >> 1;
        ans = min(ans, F(mid));
        if (F(mid) > F(mid + EPS)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << fixed << setprecision(9) << ans << '\n';
    
    return 0;
}