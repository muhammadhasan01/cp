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

int n, m, T;
vector<int> adj[N];
vector<int> adjc[N];
int tin[N], low[N], timer = 0;
int comp[N], numComponent;
stack<int> st;
int cand_cmp[N];
bitset<N> onStack, cand, bad, vis;

void tarjan(int u) {
    tin[u] = low[u] = ++timer;
    st.emplace(u); onStack[u] = 1;
    for (int v : adj[u]) {
        if (tin[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v] == 1) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] != low[u]) return;
    int w = 0; numComponent++;
    do {
        w = st.top(); st.pop();
        onStack[w] = 0;
        comp[w] = numComponent;
    } while (w != u && !st.empty());
}

void SCC() {
    for (int i = 1; i <= n; i++) {
        if (tin[i]) continue;
        tarjan(i);
    }
}

void dfs(int u) {
    vis[u] = 1;
    for (int v : adjc[u]) {
        if (vis[v] == 0) dfs(v);
        if (bad[v] == 1 || cand_cmp[v] == 1) bad[u] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> T; T++;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        if (u == T) continue;
        if (v == T) cand[u] =  true;
        adj[u].emplace_back(v);
    }
    SCC();
    debug() << imie(range(comp + 1, comp + 1 + n));
    {
        set<pair<int, int>> st;
        for (int i = 1; i <= n; i++) {
            for (int j : adj[i]) {
                if (comp[i] == comp[j]) continue;
                pair<int, int> cur = make_pair(comp[i], comp[j]);
                if (st.find(cur) != st.end()) continue;
                st.insert(cur);
                adjc[comp[i]].emplace_back(comp[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!cand[i]) continue;
        cand_cmp[comp[i]]++;
    }
    debug() << imie(numComponent);
    debug() << imie(range(cand_cmp + 1, cand_cmp + 1 + numComponent));
    for (int i = 1; i <= numComponent; i++) {
        if (cand_cmp[i] <= 1) continue;
        bad[i] = 1;
    }
    for (int i = 1; i <= numComponent; i++) {
        if (vis[i] == 1) continue;
        dfs(i);
    }
    debug() << imie(range(cand_cmp + 1, cand_cmp + 1 + numComponent));
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (cand[i] == 0) continue;
        if (bad[comp[i]] == 1) continue;
        ans.emplace_back(i);
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x - 1 << '\n';
    }

    return 0;
}