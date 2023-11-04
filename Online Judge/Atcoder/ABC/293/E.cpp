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

long long egcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1;
    long long d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

long long binpow(long long x, long long y, long long m) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) {
            ret = (ret * x) % m;
        }
        x = (x * x) % m;
        y >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long a, x, m;
    cin >> a >> x >> m;
    if (a == 1) {
        cout << x % m << '\n';
        return 0;
    }
    // (a^x - 1) / (a - 1) = res (mod m)
    // (a^x - 1) = res * (a - 1) (mod m)
    // res * (a - 1) = (a^x - 1) (mod m)
    // res * p = q (mod m)
    // p * (res) + m * (temp) = q
    // gcd(p, m) | q
    long long p = (a - 1) % m;
    long long q = ((binpow(a, x, m) - 1) % m + m) % m;
    long long res, temp;
    long long g = egcd(p, m, res, temp);
    assert(q % g == 0);
    long long d = q / g;
    res = (((res * d) % m) + m) % m;
    cout << res << '\n';
    long long res2 = 0;
    for (int i = 0; i < x; i++) {
        res2 = (res2 + binpow(a, i, m)) % m;
    }
    cout << res2 << '\n';
    debug() << imie(p) imie(q) imie(g) imie(temp) imie(res) imie(res2);
    // assert(res == res2);
    
    return 0;
}#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b, ll mod) {
	// 行列乗算
	int n = a.size();
	vector<vector<ll>> res(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= mod;
			}
		}
	}
	return res;
}
vector<vector<ll>> mat_pow(vector<vector<ll>> a, ll b, ll mod) {
	// Matrix exponentiation
	int n = a.size();
	vector<vector<ll>> res(n, vector<ll>(n));
	for (int i = 0; i < n; i++) res[i][i] = 1;
	while (b) {
		if (b & 1) res = mat_mul(res, a, mod);
		a = mat_mul(a, a, mod);
		b >>= 1;
	}
	return res;
}
int main() {
	ll a, x, m;
	cin >> a >> x >> m;
	vector<vector<ll>> f = { {a,1},{0,1} };
	vector<vector<ll>> g = mat_pow(f, x, m);
	cout << g[0][1] << '\n';
}