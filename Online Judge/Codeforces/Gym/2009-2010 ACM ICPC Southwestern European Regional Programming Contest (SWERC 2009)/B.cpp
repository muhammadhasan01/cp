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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> st(2);
        for (int rep = 0; rep < n; rep++) {
            string s; cin >> s;
            int x; cin >> x;
            debug() << imie(s) << imie(x);
            if (s[0] == 'D') {
                cout << "DROP 2 " << x << '\n';
                st[1] += x;
            } else {
                while (x > 0) {
                    if (st[0] == 0) {
                        cout << "MOVE 2->1 " << st[1] << '\n';
                        st[0] += st[1], st[1] = 0;
                    } else {
                        int mini = min(st[0], x);
                        cout << "TAKE 1 " << mini << '\n';
                        st[0] -= mini, x -= mini;
                    }
                }
            }
        }
    }

    return 0;
}