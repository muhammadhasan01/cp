#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b, x, y, n;

void solve() {
    cin >> a >> b >> x >> y >> n;
    long long _a = a, _b = b, _x = x, _y = y, _n = n;
    long long res = 1e18;
    for (int it = 0; it < 2; it++) {
        long long dif = a - x;
        if (n <= dif) {
            a -= n;
        } else {
            n -= dif;
            a = x;
            dif = b - y;
            if (n <= dif) {
                b -= n;
            } else {
                b = y;
            }
        }
        res = min(res, a * b);
        b = _a, a = _b;
        x = _y, y = _x;
        n = _n;
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}