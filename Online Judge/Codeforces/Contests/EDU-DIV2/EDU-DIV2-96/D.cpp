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

void solve() {
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<int> st;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) st.emplace(i);
    }
    int res = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        debug() << imie(i);
        ++res;
        if (i >= n - 2) {
            break;
        }
        auto it = st.lower_bound(i);
        if (it == st.end()) {
            ++i;
            while (i < n && vis[i]) ++i;
        } else {
            vis[*it] = 1;
            st.erase(it);
        }
        int cur = n - 1;
        for (int j = i; j < n; j++) {
            if (vis[j]) continue;
            if (v[i] != v[j]) {
                cur = j - 1;
                break;
            }
        }
        i = cur;
        debug() << imie(res) imie(vis);
    }
    cout << res << '\n';
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