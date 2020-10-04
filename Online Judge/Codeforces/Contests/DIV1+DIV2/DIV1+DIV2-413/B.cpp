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
const int INF = 2e9;

int n, m;
int p[N], a[N], b[N];
vector<int> v[5][5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        v[a[i]][b[i]].emplace_back(p[i]);
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            sort(v[i][j].rbegin(), v[i][j].rend());
        }
    }
    cin >> m;
    for (int rep = 1; rep <= m; rep++) {
        int c;
        cin >> c;
        int pi = -1, pj = -1, res = INF;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                if (i != c && j != c) continue;
                if (v[i][j].empty()) continue;
                if (v[i][j].back() < res) {
                    res = v[i][j].back();
                    pi = i, pj = j;
                }
            }
        }
        if (pi != -1) {
            v[pi][pj].pop_back();
        } else {
            res = -1;
        }
        cout << res << (rep == m ? '\n' : ' ');
    }

    return 0;
}