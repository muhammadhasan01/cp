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

long long getValue(int len, int parts) {
    int len1 = len / parts;
    int len2 = len1 + 1;
    int cnt2 = len % parts;
    int cnt1 = parts - cnt2;
    return (1LL) * cnt1 * len1 * len1 + (1LL) * cnt2 * len2 * len2;
}

struct S {
    int len, parts;
    long long get() const {
        return getValue(len, parts) - getValue(len, parts + 1);
    }
    bool operator<(const S& other) const {
        return get() > other.get();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    multiset<S> ms;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ms.insert(S{x, 1});
    }
    for (int it = 0; it < k - n; it++) {
        S s = *ms.begin();
        ms.erase(ms.begin());
        ms.insert(S{s.len, s.parts + 1});
    }
    long long ans = 0;
    for (S s : ms) {
        ans += getValue(s.len, s.parts);
    }
    cout << ans << '\n';

    return 0;
}