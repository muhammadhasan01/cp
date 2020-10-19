#include <bits/stdc++.h>

using namespace std;

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

const int N = 1e5 + 5;

int n;
long long a[N];
long long pre[N];

long long solve() {
    long long ret = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    pq.emplace(0);
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + abs(a[i] - a[i + 1]) * (i & 1 ? 1LL : -1LL);
        ret = max(ret, pre[i]);
        if (i & 1) {
            ret = max(ret, pre[i] - pq.top());
        } else {
            pq.emplace(pre[i]);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = solve();
    for (int i = 1; i < n; i++) {
        a[i] = a[i + 1];
    }
    n--;
    ans = max(ans, solve());
    cout << ans << '\n';

    return 0;
}