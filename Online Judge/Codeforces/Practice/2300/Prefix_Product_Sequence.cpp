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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES" << '\n';
        cout << 1 << '\n';
        return 0;
    }
    if (n == 4) {
        cout << "YES" << '\n';
        cout << "1\n3\n2\n4" << '\n';
        return 0;
    }

    auto isPrime = [&](int x) -> bool {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }   
        return true;
    };

    if (!isPrime(n)) {
        cout << "NO" << '\n';
        return 0;
    }

    auto modpow = [&](long long x, long long y, long long p) -> long long { 
        long long ret = 1;
        while (y > 0) {
            if (y & 1) ret = (ret * x) % p;
            y >>= 1;
            x = (x * x) % p;
        }
        return ret;
    };

    auto inv = [&](long long x) -> long long {
        return modpow(x, n - 2, n);
    };

    cout << "YES" << '\n';
    cout << 1 << '\n';
    for (int i = 2; i <= n - 1; i++) {
        cout << ((1LL) * i * inv(i - 1)) % (1LL * n) << '\n';// i / (i - 1)
    }
    cout << n << '\n';

    return 0;
}