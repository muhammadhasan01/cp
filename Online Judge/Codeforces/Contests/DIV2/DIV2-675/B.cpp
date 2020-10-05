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

const int N = 1e2 + 5;
const long long INF = 1e18;

int tc;
int n, m;
int a[N][N];
int par[N * N];

int getId(int x, int y) {
    return m * (x - 1) + y;
}

int fpar(int u) {
    if (par[u] == u) return u;
    return par[u] = fpar(par[u]);
}

void merge(int u, int v) {
    int pu = fpar(v);
    int pv = fpar(u);
    if (pu == pv) return;
    par[pv] = pu;
}

void init() {
    for (int i = 1; i <= n * m; i++) {
        par[i] = i;
    }
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int u = getId(i, j);
            int v = getId(i, m - j + 1);
            merge(u, v);
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int u = getId(i, j);
            int v = getId(n - i + 1, j);
            merge(u, v);
        }
    }
    vector<vector<int>> res(n * m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int id = getId(i, j);
            debug() << imie(i) imie(j) imie(id) imie(fpar(id));
            res[fpar(id)].emplace_back(a[i][j]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n * m; i++) {
        if (res[i].empty()) continue;
        debug() << imie(i) imie(res[i]);
        long long rescur = INF;
        for (int x : res[i]) {
            long long cur = 0;
            for (int y : res[i]) {
                cur += (1LL) * abs(x - y);
            }
            rescur = min(rescur, cur);
        }
        ans += rescur;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}