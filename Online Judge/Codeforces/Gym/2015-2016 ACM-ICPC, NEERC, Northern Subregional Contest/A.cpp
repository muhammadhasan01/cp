#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-9;

long double h, w;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifndef ONLINE_JUDGE
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
    // #endif
    cin >> h >> w;
    if (h > w) swap(h, w);
    long double ans = h / 2.0;
    long double l = 0, r = 1e5, res = 0;
    while (r - l > eps) {
        long double mid = (l + r) / 2.0;
        if (mid * 3 <= w && mid <= h) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ans = max(ans, l);
    cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}