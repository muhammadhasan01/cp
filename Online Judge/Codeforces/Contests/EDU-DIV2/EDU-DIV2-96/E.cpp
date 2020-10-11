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

int n;
char s[N];
int bit[N];
deque<int> pos[30];

void add(int x) {
    for ( ; x > 0; x -= x & -x) {
        bit[x]++;
    }
}

int get(int x) {
    int ret = 0;
    for ( ; x <= n; x += x & -x) ret += bit[x];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        pos[(int) (s[i] - 'a')].emplace_back(i);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int alf = s[n - i + 1] - 'a';
        int cur = pos[alf].front(); pos[alf].pop_front();
        res += get(cur);
        add(cur);
    }
    cout << res << '\n';

    return 0;
}