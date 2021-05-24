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

const int N = 15;
const int INF = 2e9;

int n, m;
int a[N];
int p[N], val[N];
bool vis[N];

pair<int, int> rec(int x) {
    if (x > m) return make_pair(0, 0);
    pair<int, int> cur = make_pair(0, INF);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        pair<int, int> temp = rec(x + 1);
        temp.first += min(val[x], p[x] * a[i] / 100);
        temp.second += a[i];
        if (temp.first > cur.first || (temp.first == cur.first && temp.second < cur.second)) {
            cur = temp;
        }
        vis[i] = false;
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> p[i] >> val[i];
    }
    pair<int, int> ans = rec(1);
    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}