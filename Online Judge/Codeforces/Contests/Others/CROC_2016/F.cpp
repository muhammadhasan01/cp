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

const int N = 2e5 + 5;
const int A = 1e6 + 5;
const long long M = 1e9 + 7;


int n, k, q;
int val[N];
int use[A], phi[A], cnt[A];
vector<int> divisors[A];
long long fact[N];
long long invf[N];

void read() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n + q; i++) {
        cin >> val[i];
        use[val[i]] = 1;
    }
}

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
    iota(phi, phi + A, 0);
    for (int i = 1; i < A; i++) {
        for (int j = i; j < A; j += i) {
            if (i != j) phi[j] -= phi[i];
            if (use[j]) divisors[j].emplace_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    read();
    init();
    long long res = 0;
    for (int i = 1; i <= n + q; i++) {
        for (int d : divisors[val[i]]) {
            long long cur = C(cnt[d] + 1, k) - C(cnt[d], k);
            cur = (cur % M + M) % M;
            res = (res + cur * phi[d]) % M;
            cnt[d]++;
        }
        if (i > n) {
            cout << res << '\n';
        }
    }

    return 0;
}