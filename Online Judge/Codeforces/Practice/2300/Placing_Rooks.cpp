#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int M = 998244353;
const int N = 2e5 + 5;

long long fact[N];
long long invf[N];

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

long long inv(long long x) {
    return modpow(x, M - 2);
}

long long C(int a, int b) {
    if (a < b) return 0;
    long long ret = (fact[a] * invf[b]) % M;
    ret = (ret * invf[a - b]) % M;
    return ret;
}

void init() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
        invf[i] = inv(fact[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int n, k;
    cin >> n >> k;
    if (k > n - 1) {
        cout << 0 << '\n';
        return 0;
    }
    int c = n - k;
    long long ans = 0;
    for (int i = 0; i <= c; i++) {
        long long cur = (C(c, i) * modpow(i, n)) % M;
        if (i % 2 == c % 2)
            ans = (ans + cur) % M;
        else
            ans = ((ans - cur) % M + M) % M;
    }
    ans = (ans * C(n, c)) % M;
    if (k > 0) ans = (ans + ans) % M;
    cout << ans << '\n';

    return 0;
}