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

const int N = 2e2 + 5;

int tc;
int n, m;
int par[N], deg[N];
set<pair<int, int>> adj[N];
vector<pair<int, int>> ans;
vector<int> odd_nodes[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

void init() {
    ans.clear();
    for (int i = 1; i <= n; i++) {
        adj[i].clear(), odd_nodes[i].clear();
        par[i] = i;
        deg[i] = 0;
    }
}

void add_edges() {
    for (int i = 1; i <= n; i++) {
        if (odd_nodes[i].empty()) continue;
        int len = odd_nodes[i].size();
        debug() << imie(i) imie(odd_nodes[i]);
        assert(len % 2 == 0);
        for (int j = 1; j < len; j += 2) {
            int u = odd_nodes[i][j - 1], v = odd_nodes[i][j];
            deg[u]++, deg[v]++;
            adj[u].emplace(v, 0);
            adj[v].emplace(u, 0);
        }
    }
}

void euler_circuit(int u) {
    stack<int> st;
    st.emplace(u);
    while (!st.empty()) {
        debug() << imie(u) imie(adj[u]);
        if (!adj[u].empty()) {
            auto e = *adj[u].begin();
            int v = e.first, id = e.second;
            if (id == 1)
                ans.emplace_back(u, v);
            adj[u].erase(adj[u].begin());
            adj[v].erase(make_pair(u, id));
            u = v;
        } else {
            u = st.top();
            st.pop();
        }
    }
    debug() << imie(u) << imie(ans);
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
        merge(u, v);
        adj[u].emplace(v, 1);
        adj[v].emplace(u, 1);
    }
    int counter = 0;
    for (int i = 1; i <= n; i++) {
        int parent = fpar(i);
        debug() << imie(i) imie(parent) imie(deg[i]);
        if (deg[i] % 2 == 0) {
            ++counter;
            continue;
        }
        odd_nodes[parent].emplace_back(i);
    }
    add_edges();
    for (int i = 1; i <= n; i++) {
        euler_circuit(i);
    }
    cout << counter << '\n';
    int len = ans.size();
    // assert(len == m);
    for (int i = 0; i < len; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
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