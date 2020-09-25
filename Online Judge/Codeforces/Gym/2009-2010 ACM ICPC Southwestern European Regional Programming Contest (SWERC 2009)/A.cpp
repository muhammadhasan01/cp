#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

/** START OF TEMPLATE DEBUGGER **/
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
/** END OF TEMPLATE DEBUGGER **/

using ld = double;

const int N = 5e4 + 5;
const ld INF = 2e5;

int n;
pair<ld, ld> p[N];

ld F(ld x) {
    ld ret = 0;
    for (int i = 1; i <= n; i++) {
        ld dx = p[i].first - x; dx *= dx;
        ld dy = p[i].second; dy *= dy;
        ret = max(ret, dx + dy);
    }
    return ret;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &p[i].first, &p[i].second);
    }
    ld l = -INF, r = INF;
    for (int rep = 0; rep < 100; rep++) {
        ld p1 = l + (r - l) / 3.0;
        ld p2 = r - (r - l) / 3.0;
        debug() << imie(l) << imie(r);
        if (F(p1) > F(p2)) {
            l = p1;
        } else {
            r = p2;
        }
    }
    printf("%.9lf %.9lf\n", l, sqrt(F(l)));
}

int main() {
    while (1) {
        in(n);
        if (n == 0) break;
        solve();
    }
    return 0;
}