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

vector<pair<int, int>> ans;

void build(int s, int e) {
    if (s == e) return;
    int mid = (s + e) >> 1;
    build(s, mid);
    build(mid + 1, e);
    for (int i = 0; i < mid - s + 1; i++) {
        ans.emplace_back(s + i, mid + 1 + i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int m = 1;
    while (m + m <= n) {
        m <<= 1;
    }
    build(1, m);
    if (m < n) build(n - m + 1, n);
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}