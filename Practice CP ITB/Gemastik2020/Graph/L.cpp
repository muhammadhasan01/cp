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

const int N = 3e5 + 5;

int n, m;
int index[N], low[N], tim;
int comp[N], num_com;
stack<int> st;
bool on_stack[N];
vector<pair<int, int>> adj[N];

void tarjan(int u, int p) {
    index[u] = low[u] = ++tim;
    st.emplace(u); on_stack[u] = 1;
    for (auto e : adj[u]) {
        int v = e.first;
        if (v == p) continue;
        if (index[v] == 0) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (on_stack[v]) {
            low[u] = min(low[u], index[v]);
        }
    } 
    if (low[u] != index[u]) return;
    ++num_com;
    int w = 0;
    do {
        w = st.top(); st.pop();
        comp[w] = num_com;
        on_stack[w] = false;
    } while (u != w && !st.empty());
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    tarjan(1, 1);
    vector<int> good(num_com + 1);
    vector<set<pair<int, int>>> new_adj(num_com + 1);
    for (int i = 1; i <= n; i++) {
        for (auto e : adj[i]) {
            int j = e.first;
            int k = e.second;
            if (comp[i] == comp[j])
                good[comp[i]] |= (e.second);
            else
                new_adj[comp[i]].emplace(comp[j], k);
        }
    }
    int s, t;
    cin >> s >> t;
    s = comp[s], t = comp[t];
    debug(s, t);
    queue<int> q;
    vector<bool> vis(num_com + 1);
    q.emplace(s);
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        debug(u);
        for (auto e : new_adj[u]) {
            int v = e.first;
            debug(u, v);
            if (vis[v]) continue;
            if (e.second)
                good[v] = 1;
            good[v] |= good[u];
            q.emplace(v);
            vis[v] = 1;
        }
    }
    cout << (good[t] ? "YES" : "NO") << '\n';

    return 0;
}