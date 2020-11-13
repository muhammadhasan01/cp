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
const int M = 2 * N;

int n;
vector<int> adj[N];
int depth[N];
int eul[M], tin[M], tout[M], tim;
int block;
int cnt[N], ans[N];
set<pair<int, int>> st_cnt;

struct st {
    int l, r, idx;
    bool operator<(const st& o) {
        return make_pair(l / block, r) < make_pair(o.l / block, o.r);
    };
} query[N];

void dfs(int u, int p) {
    depth[u] = 1 + depth[p];
    eul[++tim] = depth[u]; tin[u] = tim;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    eul[++tim] = depth[u]; tout[u] = tim;
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
    for (int i = 1; i <= n; i++) {
        query[i] = {tin[i], tout[i], i};
    }
    block = sqrt(n) + 1;
    sort(query + 1, query + 1 + n);
    int cur_l = 1, cur_r = 0;
    for (int i = 1; i <= n; i++) {
        int L = query[i].l, R = query[i].r;
        while (cur_l < L) del(eul[cur_l++]);
        while (cur_l > L) add(eul[--cur_l]);
        while (cur_r < R) add(eul[++cur_r]);
        while (cur_r > R) del(eul[cur_r--]);
        int cur_depth = (st_cnt.begin()->second);
        int id = query[i].idx;
        ans[id] = cur_depth - depth[id]; 
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}