#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const ll M = 1e9 + 7;
const ll m = 5e8 + 3;
const ll prod = 1e9 + 6;
int q;
int a, b, c;
ll fact[N], invf[N];
ll t1, t2;

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

ll inv(ll a, ll m) {
    ll x, y;
    egcd(a, m, x, y);
    return (x % m + m) % m;
}

ll Cm(ll b, ll c) {
    ll ret = fact[b];
    ret = (ret * invf[b - c]) % m;
    ret = (ret * invf[c]) % m;
    return (ret % m + m) % m;
}

ll C2(ll b, ll c) {
    for (int i = 20; i >= 0; i--) {
        bool bi = (b & (1LL << i));
        bool ci = (c & (1LL << i));
        if (!bi && ci) return 0;
    }
    return 1;
}

ll C(ll b, ll c) {
    ll rm = Cm(b, c), r2 = C2(b, c);
    ll res = (m * t1 * r2) % prod;
    ll res2 = (2 * t2 * rm) % prod;
    res = (res + res2) % prod;
    return (res % prod + prod) % prod;
}

ll fast(ll x, ll y) {
    ll ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return (ret % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    invf[0] = inv(fact[0], m);
    for (ll i = 1; i <= N - 5; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= m;
        invf[i] = inv(fact[i], m);
    }

    t1 = inv(m, 2);
    t2 = inv(2, m);

    cin >> q;
    while (q--) {
        cin >> a >> b >> c;
        cout << (fast(a, C(b, c)) % M + M) % M << '\n';
    }

    return 0;
}
