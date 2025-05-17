#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        ll k, d;
        cin >> k >> d;
        if (k == 1) {
            if (d % 2 == 0 && d / 2 >= 1) {
                ll x = d / 2;
                cout << x << " " << 1 << "\n";
            } else {
                cout << "impossible\n";
            }
            continue;
        }
        if ((k & 1) == 0) {
            if (d % k != 0) {
                cout << "impossible\n";
            } else {
                ll S = d / k;
                if (S < 2) {
                    cout << "impossible\n";
                } else {
                    cout << 1 << " " << (S - 1) << "\n";
                }
            }
            continue;
        }
        if (d % 2 != 0 || d < 2*k) {
            cout << "impossible\n";
            continue;
        }
        ll t = (k - 1) / 2;
        ll D = d / 2;
        ll r = D % t;
        ll x = (r == 0 ? t : r);
        ll num = D - (t + 1) * x;
        ll y = num / t;
        if (x >= 1 && y >= 1) {
            cout << x << " " << y << "\n";
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}