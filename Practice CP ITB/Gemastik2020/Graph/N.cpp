/**
never mind, to long to try :(
**/
#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

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
const int M = 1e6 + 5;

int n, m;
int par[N];
int tin[N], low[N], timer;
int col[N], comp[N], numComponent;
int sz[N];
set<int> colPar[N];
unordered_map<int, int> mpPar[N];
map<int, int> mpComp[N]
stack<int> st;
bool onStack[N];
vector<int> adj[N];
vector<int> adjSCC[N];
int curChild;
int cnt[M];
long long ans;
long long res[N];

int fpar(int u) {
    return (par[u] == u ? u : par[u] = fpar(par[u]));
}

void merge(int u, int v) {
    int pu = fpar(u), pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

void tarjan(int u, int p) {
    tin[u] = low[u] = ++timer;
    st.emplace(u); onStack[u] = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (tin[v] == 0) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] != low[u]) return;
    int w = 0; numComponent++;
    do {
        w = st.top(); st.pop();
        comp[w] = numComponent;
        onStack[w] = false;
    } while (u != w && !st.empty());
}

void dfs_sz(int u, int p) {
    sz[u] = 1;
    for (int v : adjSCC[u]) {
        if (v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}

void add(int u, int p, int val) {
    for (const auto& e : mpComp[u]) {
        col[e.first] += val * e.second;
    }
    for (int v : adjSCC[u]) {
        if (v == p || v == curChild) continue;
        add(v, u, val);
    }
}

void dfs(int u, int p, bool keep) {
    int mx = -1, bigChild = -1;
    for (int v : adjSCC[u]) {
        if (v == p) continue;
        if (sz[v] > mx) {
            mx = sz[v], bigChild = v;
        }
    }
    for (int v : adjSCC[u]) {
        if (v == p || v == bigChild) continue;
        dfs(v, u, 0);
    }
    if (bigChild != -1)
        dfs(bigChild, u, 1);
    curChild = bigChild;
    add(u, p, 0);
    if (u != p) {
        res[fpar(p)]
    }
    if (keep == 0) {
        curChild = -1;
        add(u, p, -1);
    }
}

inline void SCC() {
    for (int i = 1; i <= n; i++) {
        if (tin[i]) continue;
        tarjan(i, i);
    }
    debug() << imie(range(comp + 1, comp + 1 + n));
    for (int i = 1; i <= n; i++) {
        mpComp[comp[i]][col[i]]++;
        for (int j : adj[i]) {
            if (comp[i] == comp[j]) continue;
            adjSCC[comp[i]].emplace_back[comp[j]];
        }
    }
    for (int i = 1; i <= numComponent; i++) {
        sort(adjSCC[i].begin(), adjSCC[i].end());
        adjSCC[i].resize(unique(adjSCC[i].begin(), adjSCC[i].end()) - adjSCC[i].begin());
    }
}

inline long long initialAnswer() {
    long long ret = 0;
    vector<int> cc;
    for (int i = 1; i <= n; i++) {
        int parent = fpar(i);
        debug() << imie(i) imie(parent);
        colPar[parent].emplace(col[i]);
        mpPar[parent][col[i]]++;
        if (i == parent) cc.emplace_back(i);
    }
    unordered_map<int, int> mpCur;
    for (int u : cc) {
        for (int color : colPar[u]) {
            ret += (1LL) * mpCur[color] * mpPar[u][color];
            mpCur[color] += mpPar[u][color];
            debug() << imie(u) imie(color) imie(ret);
        }
    }
    return ret;
}

long long disconnect(int u) {
    long long ret = 0;
    int parent = fpar(u);
    ret += (1LL) * (mpPar[parent][col[u]] - 1);
    debug() << imie(u) imie(parent) imie(ret);
    vector<int> components;
    for (int v : adj[u]) {
        components.emplace_back(comp[v]);
    }
    sort(components.begin(), components.end());
    components.resize(unique(components.begin(), components.end()) - components.begin());
    long long cur = 0;
    debug() << imie(u) imie(components) imie(comp[u]);
    for (int component : components) {
        long long curval = mpComp[component][col[u]] - int(component == comp[u]);
        ret += cur * curval, cur += curval;
        debug() << imie(cur) imie(component) imie(curval) imie(ret);
    }
    debug() << imie(u) imie(ret);
    return ret;
}

inline void getAnswer() {
    for (int u = 1; u <= n; u++) {
        long long result = ans + disconnect(u);
        out(result, '\n');
    }
}

int main() {
    in(n), in(m);
    for (int i = 1; i <= n; i++) {
        in(col[i]);
        par[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        in(u), in(v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        merge(u, v);
    }
    ans = initialAnswer();
    debug() << imie(ans);
    SCC();
    getAnswer();
    return 0;
}