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
    vector<int> first(n + 1, -1), last(n + 1, -1);
    vector<int> oc(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (first[a[i]] < 0) first[a[i]] = i;
        last[a[i]] = i;
        oc[a[i]]++;
    }
    vector<int> dp(n + 1);
    vector<int> cur_oc(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = dp[i + 1];
        cur_oc[a[i]]++;
        if (i == first[a[i]])
            dp[i] = max(dp[i], oc[a[i]] + dp[last[a[i]] + 1]);
        else
            dp[i] = max(dp[i], cur_oc[a[i]]);
    }
    cout << n - dp[0] << '\n';

    return 0;
}