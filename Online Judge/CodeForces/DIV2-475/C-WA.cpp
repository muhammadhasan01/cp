#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e9 + 9;
const int N = 1e5 + 5;
ll n,a,b, k;
char s[N];

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
    return (x % b + b) % b;
}

ll fast(ll x, int y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % M;
        }
        y >>= 1;
        x = (x * x) % M;
    }
    return (res % M + M) % M;
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
            res %= M;
        } else {
            res -= fast(a, n - i) * fast(b, i);
            res %= M;
        }
    }
    ll bk = fast(b, k);
    ll ak = inv(fast(a, k), M);
    ll ck = ((bk * ak) % M + M) % M;
    ll m = (n + 1)/k;
    ll upp = ((fast(ck, m) - 1) % M + M ) % M;
    ll downn = inv(((ck - 1) % M + M) % M, M);
    res *= upp;
    res %= M;
    res *= downn;
    res %= M;
    cout << (res % M + M) % M << '\n';


    return 0;
}
