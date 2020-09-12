#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int N = 1e5 + 5;
const int INF = 2e9;

int tc;
int n;
vector<int> adj[N];
int sz[N], maks[N];
vector<int> cent;

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        maks[i] = 0;
    }
}

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        maks[u] = max(maks[u], sz[v]);
    }
    if (u != 1)
        maks[u] = max(maks[u], n - sz[u]);
}

int get(int u, int p, int x) {
    for (int v : adj[u]) {
        if (v == p || v == x) continue;
        return get(v, u, x);
    }
    return u;
}

void solve() {
    cin >> n;
    init();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    int mini = INF;
    for (int i = 1; i <= n; i++) {
        debug(i, maks[i]);
        mini = min(mini, maks[i]);
    }
    debug(mini);
    vector<int> comp;
    for (int i = 1; i <= n; i++) {
        if (mini == maks[i])
            comp.emplace_back(i);
    }
    debug(comp);
    int len = comp.size();
    if (len == 1) {
        cout << 1 << " " << adj[1][0] << '\n';
        cout << 1 << " " << adj[1][0] << '\n';
        return;
    }
    int x = comp[0], y = comp[1];
    int leave = get(x, x, y);
    debug(x, y, leave);
    for (int v : adj[x]) {
        if (v == y) continue;
        cout << x << " " << v << '\n';
        break;
    }
    cout << leave << " " << y << '\n';
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