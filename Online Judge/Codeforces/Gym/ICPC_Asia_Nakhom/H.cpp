#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll tc;
ll x[5], y[5];
long double k;

ll egcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    ll d = egcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll inv(ll a, ll b) {
    ll x, y;
    egcd(a, b, x, y);
    return (x % b + b) % b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        for (int i = 1; i <= 3; i++) cin >> x[i];
        for (int i = 1; i <= 3; i++) cin >> y[i];
        for (ll i = 0; i < (1 << 21); i++) {
            bool ok = true;
            ll k = i * i * i;
            for (int j = 1; j <= 3; j++) {
                if (k % x[j] != y[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
