#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long n, p, w, d;

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> w >> d;
    ll x, y;
    ll g = egcd(w, d, x, y);
    if (p % g != 0) {
        puts("-1");
        return 0;
    }
    p /= g, w /= g, d /= g;
    //cerr << (y % w + w) % w << '\n';
    ll x1, y1;
    y1 = ((p % w) * ((y % w + w) % w)) % w;
    x1 = (p - d * y1) / w;
    //cerr << x1 << " and " << y1 << '\n';
    if (x1 < 0 || y1 < 0 || (x1 + y1) > n) {
        puts("-1");
        return 0;
    }
    cout << x1 << " " << y1 << " " << n - x1 - y1 << '\n';

    return 0;
}
