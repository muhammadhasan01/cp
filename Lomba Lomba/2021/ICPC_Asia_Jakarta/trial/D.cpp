#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

using ll = long long;

int n, q;
vector<int> adj[N];

vector<int> path;

int par[N];

struct Lazy {
    ll lazy[N * 4];
    ll t[N * 4];

    void build(int v, int tl, int tr){
        if (tl == tr){
            t[v] = 0;
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
    void push(int v, int tl, int tr){
        int tm = (tl + tr) / 2;
        lazy[v * 2] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        t[v * 2] += lazy[v] * (tm - tl + 1);
        t[v * 2 + 1] += lazy[v] * (tr - tm);
        lazy[v] = 0;
    }
    void update(int v, int tl, int tr, int l, int r, ll val){
        if (l > r || tr < l || r < tl) return;
        if (l <= tl && tr <= r){
            t[v] += val * (tr - tl + 1);
            lazy[v] += val;
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, r, val);
        update(v * 2 + 1, tm + 1, tr, l, r, val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
    ll ask(int v, int tl, int tr, int l, int r){
        if (l > r || tr < l || r < tl) return 0;
        if (l <= tl && tr <= r) return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return ask(v * 2, tl, tm, l, r) + ask(v * 2 + 1, tm + 1, tr, l, r);
    }
};

int tin[N], tout[N];

void dfs_euler(int node, int p){
    par[node] = p;
    tin[node] = path.size();
    path.push_back(node);
    for (auto& x : adj[node]) {
        if (x == p) continue;
        dfs_euler(x, node);
    }
    tout[node] = path.size() - 1;
}

const int MDEP = 17;

int dp[N][MDEP];
ll score[N];
void dfs_dp(int node, int p){
    dp[node][0] = 1;
    for (auto& x : adj[node]){
        if (x == p) continue;
        dfs_dp(x, node);
        for (int i=1;i<MDEP;i++){
            dp[node][i] += dp[x][i - 1];
        }
    }
}

Lazy stree1;
Lazy stree2;
ll applied[N][MDEP];

int main() {
    cin >> n >> q;
    for (int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs_euler(1, 1);
    int len = path.size();
    dfs_dp(1, 1);

    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int x, k;
            ll y;
            cin >> x >> y >> k;
            if (k == 1){
                stree1.update(1, 0, len - 1, tin[x], tout[x], y);
            } else{
                // update ke atas
                ll tot = 0;
                ll bg = 1;
                for (int i=0;i<MDEP;i++){
                    tot += (y / bg) * dp[x][i];

                    applied[x][i] += (y / bg);
                    bg *= k;
                    if (bg > y) break;
                }
                stree2.update(1, 0, len - 1, tin[x], tin[x], tot);
            }
        } else{
            int x;
            cin >> x;

            ll tam = 0;
            int id = 1;
            int cur = x;
            while (par[cur] != cur && id < MDEP){
                cur = par[cur];
                for (int i=id;i<MDEP;i++){
                    tam += applied[cur][i] * dp[x][i - id];
                }
                id++;
            }
            ll a = stree1.ask(1, 0, len - 1, tin[x], tout[x]);
            ll b = stree2.ask(1, 0, len - 1, tin[x], tout[x]);
            ll c = tam;
            cout << a + b + c << '\n';
        }
    }

    return 0;
}