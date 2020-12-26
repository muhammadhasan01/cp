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

    const int Q = 5e5 + 5;

    set<int> st;
    set<pair<int, int>> spt;
    vector<int> vals(Q);

    int q;
    cin >> q;
    int nums = 0;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int m;
            cin >> m;
            vals[++nums] = m;
            st.emplace(nums);
            spt.emplace(-m, nums);
        } else if (tp == 2) {
            int cur = *st.begin();
            cout << cur << ' ';
            st.erase(st.begin());
            spt.erase(make_pair(-vals[cur], cur)); 
        } else if (tp == 3) {
            pair<int, int> cur = *spt.begin();
            cout << cur.second << ' ';
            st.erase(cur.second);
            spt.erase(spt.begin());
        }
    }
    cout << '\n';

    return 0;
}