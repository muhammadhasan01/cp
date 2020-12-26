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

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    int dif = abs(a - b) - 1;
    int maximum_time = dif + 1 + (a < b ? (a - 1) : (n - a));

    int answer = 0;
    set<int> st;
    for (int i = 0; i < min(m, dif); i++) {
        int cur_time = min(dif, maximum_time - s[i]);
        while (cur_time > 0) {
            if (st.find(cur_time) == st.end()) {
                st.emplace(cur_time);
                break;
            } else {
                cur_time = *st.begin() - 1;
            }
        }
        if (cur_time > 0) ++answer;
    }
    cout << answer << '\n';
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