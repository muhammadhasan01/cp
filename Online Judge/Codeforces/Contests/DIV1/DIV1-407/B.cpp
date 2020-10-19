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

const int N = 1e6 + 5;

int n, m;
int par[N], deg[N];
bool loop[N];

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

void merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    int same = 0, root = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        root = u;
        if (u == v) {
            loop[u] = 1;
            ++same;
        } else {
            merge(u, v);
            deg[u]++, deg[v]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((deg[i] > 0 || loop[i]) && fpar(i) != fpar(root)) {
            cout << 0 << '\n';
            return 0;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (1LL) * deg[i] * (deg[i] - 1) / 2;
    }
    ans += (1LL) * same * (m - 1);
    ans -= (1LL) * same * (same - 1) / 2;
    cout << ans << '\n';

    return 0;
}