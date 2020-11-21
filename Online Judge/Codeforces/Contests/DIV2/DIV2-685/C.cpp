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

const int N = 1e6 + 5;

int n, k;
char a[N], b[N];
int c[30], d[30];

void init() {
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
}

void solve() {
    cin >> n >> k;
    init();
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        c[(int) (cc - 'a')]++;
    }
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        d[(int) (cc - 'a')]++;
    }
    for (int i = 0; i < 26; i++) {
        if (c[i] < d[i]) {
            cout << "No" << '\n';
            return;
        }
        int dif = (c[i] - d[i]);
        if (dif % k != 0) {
            cout << "No" << '\n';
            return;
        }
        c[i] = d[i];
        c[i + 1] += dif;
    }
    for (int i = 0; i <= 26; i++) {
        if (c[i] != d[i]) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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