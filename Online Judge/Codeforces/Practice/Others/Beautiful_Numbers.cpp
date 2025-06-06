#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 7;
const int N = 1e6 + 10;
ll a, b, n, fpb, ans;
ll maks;
ll f[N], invf[N];

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

ll inv(ll a) {
    ll x, y;
    egcd(a, M, x, y);
    return (x % M + M) % M;
}

ll get(ll m) {
    if (m >= a * n && (m - a * n) % (b - a) == 0) {
        ll x = (m - a * n) / (b - a);
        ll y = n - x;
        ll ret = f[n];
        ret = (ret * invf[x]) % M;
        ret = (ret * invf[y]) % M;
        return ret % M;
    } else {
        return 0;
    }
}

void bf(ll x) {
    ans = (ans + get(x)) % M;
    ll c1 = x * 10 + a, c2 = x * 10 + b;
    if (c1 <= maks) bf(c1);
    if (c2 <= maks) bf(c2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> n;
    maks = b * n;
    f[0] = 1; invf[0] = 1;
    for (int i = 1; i <= n + 5; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= M;
        invf[i] = inv(f[i]);
    }
    bf(0);
    cout << (ans % M + M) % M << '\n';

    return 0;
}
