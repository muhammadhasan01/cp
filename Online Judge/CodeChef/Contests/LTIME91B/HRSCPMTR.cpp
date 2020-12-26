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
    int len = n + m + 5;
    vector<vector<int>> v(n, vector<int>(m));
    vector<multiset<int>> ms(len);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            int id = i - j + m;
            ms[id].emplace(v[i][j]);
        }
    }
    vector<bool> good(len);
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (ms[i].empty() || (*ms[i].begin() == *ms[i].rbegin())) {
            good[i] = true;
            ++num;
        } 
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y, val;
        cin >> x >> y >> val;
        --x, --y;
        int id = x - y + m;
        ms[id].erase(ms[id].find(v[x][y]));
        v[x][y] = val;
        ms[id].emplace(v[x][y]);
        bool ok = (*ms[id].begin() == *ms[id].rbegin());
        if (ok) {
            if (!good[id]) {
                good[id] = 1;
                num++;
            }
        } else if (good[id]) {
            good[id] = 0;
            num--;
        }
        cout << (num == len ? "Yes" : "No") << '\n';
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