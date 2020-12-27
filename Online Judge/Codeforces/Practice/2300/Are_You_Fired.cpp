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

const int N = 5e5 + 5;
const long long INF = 1e18;

int n;
int a[N];
long long pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int x;
    cin >> x;
    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        a[i] = x;
        pre[i] = pre[i - 1] + a[i];
    }
    if (pre[n] > 0) {
        cout << n << '\n';
        return 0;
    }
    if (x >= 0) {
        cout << -1 << '\n';
        return 0;
    }
    long long maks = -INF;
    for (int i = 0; i <= n; i++) {
        maks = max(maks, pre[i] + (1LL) * x * (n - i));
        long long cur = pre[n] + (1LL) * x * (n - i);
        if (maks < cur) {
            cout << n - i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}