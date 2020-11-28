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

const int N = 1e5 + 5;

int n, m, q;
vector<int> g[N];
short int vis[N];
int par[N], sz[N], parz[N];
deque<int> dq;

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

bool merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return true;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
    return false;
}

void dfs(int u, int p) {
    dq.push_front(u);
    vis[u] = 1;
    for (auto e : g[u]) {
        if (e == p) continue;
        if (vis[e] == 0) {
            dfs(e, u);
        } else if (vis[e] == 1) {
            int p1 = fpar(e);
            for (auto el : dq) {
                int p2 = fpar(el);
                if (p2 == p1) {
                    merge(p1, u);
                    break;
                } else {
                    merge(p2, u);
                }
            }
        }
    }
    dq.pop_front();
    vis[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] != 2) {
            dfs(i, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        parz[i] = fpar(i);
    }
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (parz[u] == parz[v] ? "YES" : "NO") << '\n';
    }

    return 0;
}
