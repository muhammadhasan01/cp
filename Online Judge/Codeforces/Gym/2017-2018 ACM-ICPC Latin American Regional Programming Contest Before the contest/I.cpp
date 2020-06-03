// author : Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10, M = 17;

int n, m, q;
vector<pii> gadl[N], adl[N];
unordered_map<int, int> getcost[N];

vector<pair<int, pii>> edg;

int par[N], sz[N];
int bcost;
int tin[N], tout[N], timer;
pii up[N][M]; // node, max

void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}


int find(int a){
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void make(int a, int b, int cc){
    int ra = a, rb = b;
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    bcost += cc;
    adl[a].pb(mp(b, cc));
    adl[b].pb(mp(a, cc));
}

void dfs_init(int node, int p){
    tin[node] = ++timer;
    // up[node][0] = mp(p, getcost[node][p]);
    for (int i=1;i<M;i++){
        int atas = up[node][i - 1].fi;
        up[node][i] = mp(up[atas][i - 1].fi, max(up[atas][i - 1].se, up[node][i - 1].se));
    }
    for (auto x : adl[node]){
        if (x.fi == p) continue;
        up[x.fi][0] = mp(node, x.se);
        dfs_init(x.fi, node);
    }
    tout[node] = ++timer;
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

pii LCA(int a, int b){
    int mx = 0;
    if (!is_ancestor(a, b)){
        for (int i=M - 1;i>=0;i--){
            pii nup = up[a][i];
            if (!is_ancestor(nup.fi, b)){
                a = nup.fi;
                mx = max(mx, nup.se);
            }
        }
        pii nup = up[a][0];
        a = nup.fi;
        mx = max(mx, nup.se);
    }
    if (!is_ancestor(b, a)){
        for (int i=M - 1;i>=0;i--){
            pii nup = up[b][i];
            if (!is_ancestor(nup.fi, a)){
                b = nup.fi;
                mx = max(mx, nup.se);
            }
        }
        pii nup = up[b][0];
        b = nup.fi;
        mx = max(mx, nup.se);
    }
    return mp(a, mx);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    init();
    for (int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        gadl[a].pb(mp(b, w));
        gadl[b].pb(mp(a, w));
        edg.pb(mp(w, mp(a, b)));
        getcost[a][b] = w;
        getcost[b][a] = w;
    }
    sort(edg.begin(), edg.end());
    for (auto x : edg){
        make(x.se.fi, x.se.se, x.fi);
    }
    up[1][0] = mp(1, 0);
    dfs_init(1, 1);
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;

        int cost = getcost[a][b];
        pii lca = LCA(a, b);
        cout << bcost + cost - lca.se << el;
    }

    return 0;
}