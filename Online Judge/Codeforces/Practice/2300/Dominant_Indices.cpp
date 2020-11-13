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

int n;
vector<int> adj[N];
int depth[N], sz[N];
int eul[N], tin[N], tout[N], tim;
int cnt[N], ans[N];
set<pair<int, int>> st_cnt;

void dfs(int u, int p) {
    depth[u] = 1 + depth[p];
    sz[u] = 1;
    eul[++tim] = depth[u]; tin[u] = tim;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    tout[u] = tim;
}

void del(int x) {
    st_cnt.erase(make_pair(-cnt[x], x));
    --cnt[x];
    st_cnt.insert(make_pair(-cnt[x], x));
}
 
void add(int x) {
    st_cnt.erase(make_pair(-cnt[x], x));
    ++cnt[x];
    st_cnt.insert(make_pair(-cnt[x], x));
}

void dp(int u, int p, bool keep) {
    int mx = -1, bigChild = -1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (sz[v] > mx) {
            mx = sz[v], bigChild = v;
        }
    }
    for (int v : adj[u]) {
        if (v == p || v == bigChild) continue;
        dp(v, u, 0);
    }
    if (bigChild != -1)
        dp(bigChild, u, 1);
    for (int v : adj[u]) {
        if (v == p || v == bigChild) continue;
        for (int x = tin[v]; x <= tout[v]; x++) {
            add(eul[x]);
        }
    }
    add(depth[u]);
    ans[u] = (st_cnt.begin()->second - depth[u]);
    if (keep == 0) {
        for (int x = tin[u]; x <= tout[u]; x++) {
            del(eul[x]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    dp(1, 1, 1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}