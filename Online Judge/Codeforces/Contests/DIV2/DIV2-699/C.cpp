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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> places(n + 1);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[i] = x;
        places[x].emplace_back((a[i] != b[i]), i);
    }
    for (int i = 1; i <= n; i++) {
        sort(places[i].begin(), places[i].end());
    }
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    vector<int> ans(m, -1);
    int pos = -1;
    for (int i = m - 1; i >= 0; i--) {
        if (places[c[i]].empty()) {
            if (pos == -1) {
                cout << "NO" << '\n';
                return;
            }
            ans[i] = ans[pos];
            continue;
        }
        pos = i;
        ans[i] = places[c[i]].back().second;
        places[c[i]].pop_back();
    }
    for (int i = 0; i < m; i++) {
        a[ans[i]] = c[i];
    }
    if (a != b) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < m; i++) {
        cout << ans[i] + 1 << " \n"[i == m - 1];
    }
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