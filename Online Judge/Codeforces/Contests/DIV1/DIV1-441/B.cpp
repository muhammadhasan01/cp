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

const int N = 3e5 + 5;

int n;
int p[N];
int par[N], sz[N], ans[N];
bool vis[N];

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

void merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        par[i] = i, sz[i] = 1;
    }
    vis[n + 1] = 1;
    cout << 1 << ' ';
    for (int i = 1; i <= n; i++) {
        vis[p[i]] = 1;
        if (vis[p[i] + 1]) merge(p[i], p[i] + 1);
        if (vis[p[i] - 1]) merge(p[i], p[i] - 1);
        cout << 1 + i - sz[fpar(n + 1)] << (i == n ? '\n' : ' ');
    }

    return 0;
}