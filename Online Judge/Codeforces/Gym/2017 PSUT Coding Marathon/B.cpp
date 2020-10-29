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

const int N = 2e5 + 5;

char s[N];
int pre[N], suf[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> (s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (s[i - 1] == '(' && s[i] == ':') pre[i]++;
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (s[i] == ':' && s[i + 1] == ')') suf[i]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = pre[i] + suf[i + 1];
        if (s[1] == ':' && s[i + 1] == ')') ++cur;
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}