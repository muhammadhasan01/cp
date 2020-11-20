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

const int N = 1e5 + 5;
const long long INF = 1e9;

long long n;
long long a[N];
long long rem;

bool can(long long x) {
    long long res = 0;
    for (int i = 2; i < n; i++) {
        res += (a[n] - a[i] - x);
    }
    return (res <= a[1] + x + rem);
}

void solve() {
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    rem = (n - 1) - sum % (n - 1);
    if (rem == (n - 1)) rem = 0;
    long long l = 0, r = INF, at = INF;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            at = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << rem + at * (n - 1) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}