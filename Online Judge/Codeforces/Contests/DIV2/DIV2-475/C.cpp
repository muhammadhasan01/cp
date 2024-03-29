#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 9;
const int N = 1e5 + 5;
ll n,a,b, k;
char s[N];

ll mmod(ll a, ll b) {
    return (a % b + b) % b;
}

ll egcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    ll d = egcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll inv(ll a, ll b) {
    ll x,y;
    egcd(a,b,x,y);
    return mmod(x, b);
}

ll fast(ll x, int y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % M;
            res = mmod(res, M);
        }
        y >>= 1;
        x = (x * x) % M;
        x = mmod(x, M);
    }
    return mmod(res, M);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> k;
    ll res = 0;
    for (int i = 0; i < k; i++) {
        char x;
        cin >> x;
        if (x == '+') {
            res += fast(a, n - i) * fast(b, i);
        } else {
            res -= fast(a, n - i) * fast(b, i);
        }
        res = mmod(res, M);
    }
    ll bk = fast(b, k);
    ll ak = inv(fast(a, k), M);
    ll ck = mmod(bk * ak, M);
    ll m = (n + 1)/k;
    if (ck == 1) {
        res = res * m;
        cout << mmod(res, M) << '\n';
        return 0;
    }
    ll upp = mmod(fast(ck, m) - 1, M);
    ll downn = inv(mmod(ck - 1, M), M);
    res *= upp;
    res = mmod(res, M);
    res *= downn;
    res = mmod(res, M);
    cout << mmod(res, M) << '\n';


    return 0;
}
