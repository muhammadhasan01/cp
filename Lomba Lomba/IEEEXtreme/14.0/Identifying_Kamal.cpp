// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// const int N = 1e5 + 10;

// int n, m;
// int q;
// vector<int> adj[N];

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> m;
//     for (int i=1;i<=m;i++){
//         int a, b;
//         cin >> a >> b;
//         adj[a].pb(b);
//     }

//     return 0;
// }
#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

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

const int N = 1e5 + 5;
const int L = 20;

using pii = pair<int, int>;

int n, m, q;
vector<int> adj[N];
int tin[N], low[N], timer = 0;
int comp[N], parc[N], numComponent;
stack<int> st;
bool onStack[N];
int cnt[N];
int up[N][L];
vector<int> adj_scc[N];
int dp[N];
bool bridge[N];
map<pair<int, int>, pair<int, int>> mp;

unordered_map<int, pii> ada_edge[N];

void tarjan(int u, int p) {
    tin[u] = low[u] = ++timer;
    st.emplace(u); onStack[u] = true;
    for (auto v : adj[u]) {
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
        onStack[w] = 0;
        comp[w] = numComponent;
        cnt[comp[w]]++;
    } while (w != u && !st.empty());
}

void SCC() {
    for (int i = 1; i <= n; i++) {
        if (tin[i]) continue;
        tarjan(i, i);
    }
}

void processLCA(int u, int p) {
    dp[u] = dp[p] + (cnt[u] > 1 ? 2 : 1);
    up[u][0] = p; tin[u] = ++timer;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : adj_scc[u]) {
        if (v == p) continue;
        processLCA(v, u);
    }
    low[u] = ++timer;
}

bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && low[u] >= low[v]);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}
int bLCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void buildLCA() {
    timer = 0;
    for (int i = 1; i <= numComponent; i++) {
        tin[i] = 0;
    }
    for (int i = 1; i <= numComponent; i++) {
        if (tin[i]) continue;
        processLCA(i, i);
    }
}

// int ask(int u, int v) {
//     int cu = comp[u], cv = comp[v];
//     int w = LCA(cu, cv);
//     if (w == cv){
//         swap(u, v);
//         swap(cu, cv);
//     }
//     int ret = dp[cu] + dp[cv] - 2 * dp[w] + (cnt[w] > 1 ? 2 : 1);
    
//     if (w != cu){
//         if (u == parc[cu]) ret--;
//     } 
//     if (v == parc[cv]) ret--;
    
//     if (cu != w && cnt[w] > 1){
//         int temp = bLCA(cv, w);
//         auto edge = ada_edge[temp][w];
//         int temp2 = bLCA(cu, w);
//         auto edge2 = ada_edge[temp2][w];
//         if (edge.second == edge2.second) ret--;
//     }
    
//     // if (cnt[cu] > 1 && bridge[u]) ret--;
//     // if (cnt[cv] > 1 && bridge[v]) ret--;
//     return ret;
// }

int ppar[N], sz[N];

int find(int a){
    if (ppar[a] == a) return a;
    return ppar[a] = find(ppar[a]);
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    ppar[b] = a;
}

void init_CC(){
    for (int i=1;i<=n;i++){
        ppar[i] = i;
        sz[i] = 1;
    }
}

int askbf(int u, int v){
    int ret = 0;
    int w = LCA(comp[u], comp[v]);
    // cout << comp[u] << " " << comp[v] << " " << w << '\n';
    // cout << up[comp[u]][0] << " " << up[comp[v]][0] << '\n';
    while (comp[u] != w && ret < 10){
        ret++;
        if (u != parc[comp[u]]){
            u = parc[comp[u]];
        } else{
            auto temp = ada_edge[comp[u]][up[comp[u]][0]];
            u = temp.second;
        }
    }
    swap(u, v);
    while (comp[u] != w && ret < 20){
        ret++;
        if (u != parc[comp[u]]){
            u = parc[comp[u]];
        } else{
            auto temp = ada_edge[comp[u]][up[comp[u]][0]];
            u = temp.second;
        }
    }
    // if (ret == 20) cout << u << " " << w << '\n';
    if (comp[u] == comp[v]) ret += 2;
    else ret++;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    init_CC();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        make(u, v);
    }
    SCC();
    {
        set<pair<int, int>> done;
        for (int i = 0; i < m; i++) {
            int u = edges[i].first, v = edges[i].second;
            if (comp[u] == comp[v]) continue;
            pair<int, int> cur = make_pair(comp[u], comp[v]);
            if (done.find(cur) != done.end()) continue;
            bridge[u] = 1, bridge[v] = 1;
            done.emplace(cur);
            adj_scc[comp[u]].emplace_back(comp[v]);
            adj_scc[comp[v]].emplace_back(comp[u]);
            mp[make_pair(comp[u], comp[v])] = make_pair(u, v);
        }
    }
    buildLCA();
    
    for (int i=1;i<=n;i++){
        for (auto x : adj[i]){
            if (comp[i] != comp[x]){
                ada_edge[comp[i]][comp[x]] = make_pair(i, x);
                if (up[comp[i]][0] == comp[x]){
                    parc[comp[i]] = comp[x];
                }
            }
        }
    }
    if (n <= 3000){
        vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i == j || ppar[i] != ppar[j]) continue;
                if (comp[i] == comp[j]) pre[i][j] = 2;
                else{
                    if (j > i) pre[i][j] = askbf(i, j);
                    else pre[i][j] = pre[j][i]; 
                }
            }
        }
        cin >> q;
        while (q--){
            int a, b;
            cin >> a >> b;
            cout << pre[a][b] << '\n';
        }
        // for (int i=1;i<=n;i++){
        //     cout << i << " " << comp[i] << " " << parc[comp[i]] << '\n';
        // }
        return 0;
    }
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (comp[u] == comp[v]) {
            if (u != v) cout << 2 << '\n';
            else cout << 1 << '\n';
            continue;
        }
        cout << askbf(u, v) << '\n';   
    }

    return 0;
}