// Author : Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;

const int N = 2e5 + 10;
const ll INF = 1e18;

int n, q;
vector<pil> adj[N]; 

int dep[N], parent[N], timer;
int head[N], heavy[N], pos[N];
int lasthead[N];
ll cost[N];

int pathlen;
vector<int> path;

ll t[8 * N];
bool lazy[8 * N];

int dfs_heavy(int node, int p){
    if (node != p) dep[node] = dep[p] + 1;
    parent[node] = p;
    int ret = 1, mx = 0;
    for (auto dest : adj[node]){
        int x = dest.fi;
        if (x == p){
            cost[node] = dest.se;
            continue;
        }
        int cur = dfs_heavy(x, node);
        ret += cur;
        if (mx < cur){
            mx = cur;
            heavy[node] = x;
        }
    }
    return ret;
}

void decompose(int node, int h){
    path.pb(node);
    pos[node] = timer++;
    head[node] = h;
    if (heavy[node]){
        decompose(heavy[node], h);
    }
    for (auto dest : adj[node]){
        int x = dest.fi;
        if (x == parent[node] || x == heavy[node]) continue;
        decompose(x, x);
    }
}

void push(int v){
    if (lazy[v]){
        t[v * 2] = 0;
        t[v * 2 + 1] = 0;
        lazy[v * 2] = 1;
        lazy[v * 2 + 1] = 1;
        lazy[v] = 0;
    }
}

void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = cost[path[tl]];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
}
ll ask(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    else if (l <= tl && tr <= r){
        ll ret = t[v];
        t[v] = 0;
        lazy[v] = 1;
        return ret;
    }
    push(v);
    int tm = (tl + tr) / 2;
    ll ret = ask(v * 2, tl, tm, l, min(tm, r)) + ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = t[v * 2] + t[v * 2 + 1];
    return ret;
}

void init(){
    dfs_heavy(1, 1);
    decompose(1, 1);
    fill(lasthead, lasthead + N, -1);

    pathlen = path.size();
    build(1, 0, pathlen - 1);
}

ll query(int a, int b){
    ll ret = 0;
    for (; head[a] != head[b]; b = parent[head[b]]){
        if (dep[head[a]] > dep[head[b]]) swap(a, b);
        if (dep[b] > lasthead[head[b]]){
            ret += ask(1, 0, pathlen - 1, pos[head[b]], pos[b]);
            lasthead[head[b]] = dep[b];
        } 
    }
    if (dep[a] > dep[b]) swap(a, b);
    if (a == b) return ret;
    ret += ask(1, 0, pathlen - 1, pos[a] + 1, pos[b]);
    return ret;
}
void solve(int a, int b){
    cout << query(a, b) << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<n;i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    init();
    while (q--){
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }

    return 0;
}