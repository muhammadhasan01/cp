// Author: Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

int q;
int n;
vector<int> adj[N];
int ar[N];
int ans[N];

int _ab[2 * N], _ba[2 * N];
int * ab = _ab + N;
int * ba = _ba + N;

vector<int> tur;
int tin[N], dep[N], timer;
int pas[N];
vector<pair<pii, int>> qu;

void init(){
    fill(ans, ans + n + 2, INF);
    for (int i=1;i<=n;i++){
        adj[i].clear();
        pas[i] = 0;
    }
    timer = 0;
    tur.clear();
    qu.clear();
}


int par[N];
void dfs_bisa(int node, int p, bool& bisa){
    int cnt = 0;
    bool cbisa = 1;
    par[node] = p;
    dep[node] = dep[p] + 1;
    for (auto x : adj[node]){
        if (x == p) continue;
        cnt++;
        dfs_bisa(x, node, cbisa);
    }
    if (cnt <= 2 && cbisa){
        if (cnt == 2) bisa = 0;
    } else{
        ans[node] = -1;
        bisa = 0;
    }
}

void dfs_tur(int node){
    tur.pb(node);
    tin[node] = timer++;
    for (auto x : adj[node]){
        if (x == par[node]) continue;
        dfs_tur(x);
        if (ans[node] != -1){
            if (pas[node] != 0){
                pas[node] = 0;
            } else pas[node] = pas[x];
        }
    }
    if (par[node] != node && adj[node].size() == 1) pas[node] = node;
    if (pas[node]){
        qu.pb(mp(mp(tin[node], tin[pas[node]]), node));
    }
}

vector<int> path;
void getpath(int node){
    bool udh = 0;
    path.pb(node);
    for (auto x : adj[node]){
        if (x == par[node]) continue;
        if (udh) reverse(path.begin(), path.end());
        getpath(x);
        udh = 1;
    }
}
int _cnt[2 * N];
int * cnt = _cnt + N;
void solve_bf(int node){
    path.clear();
    getpath(node);

    int len = path.size();
    int mx = 0;
    for (int i=0;i<len;i++){
        cnt[ar[path[i]] - i]++;
        mx = max(mx, cnt[ar[path[i]] - i]);
    }
    // clear
    for (int i=0;i<len;i++){
        cnt[ar[path[i]] - i] = 0;
    }

    int lefti = 0;
    for (int i=len - 1;i>=0;i--){
        cnt[ar[path[i]] - lefti]++;
        mx = max(mx, cnt[ar[path[i]] - lefti]);
        lefti++;
    }
    // clear
    lefti = 0;
    for (int i=len - 1;i>=0;i--){
        cnt[ar[path[i]] - lefti] = 0;
        lefti++;
    }
    ans[node] = len - mx;
}

void solve(){
    cin >> n;
    init();
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool dummy = 1;
    dfs_bisa(1, 1, dummy);
    dfs_tur(1);
    
    for (int i=1;i<=n;i++){
        if (ans[i] != -1 && !pas[i]) solve_bf(i);
    }
    int l = 0, r = -1; // last
    int mx = 0;
    vector<int> ada;
    for (auto x : qu){
        pii range = x.fi;
        int node = x.se;
        if (range.se == r){
            for (int i=range.fi;i<l;i++){
                cnt[ar[tur[i]] - i]++;
                ada.pb(ar[tur[i]] - i);
                mx = max(mx, cnt[ar[tur[i]] - i]);
            }
        } else{
            for (auto y : ada){
                cnt[y] = 0;
            }
            ada.clear();
            mx = 0;
            for (int i=range.fi;i<=range.se;i++){
                cnt[ar[tur[i]] - i]++;
                ada.pb(ar[tur[i]] - i);
                mx = max(mx, cnt[ar[tur[i]] - i]);
            }
        }
        l = range.fi, r = range.se;
        ans[node] = range.se - range.fi + 1 - mx;
    }
    for (auto x : ada){
        cnt[x] = 0;
    }
    ada.clear();
    l = 0, r = -1;
    mx = 0;
    for (auto x : qu){
        pii range = x.fi;
        int node = x.se;
        if (range.se == r){
            for (int i=range.fi;i<l;i++){
                cnt[ar[tur[i]] - (n - i)]++;
                ada.pb(ar[tur[i]] - (n - i));
                mx = max(mx, cnt[ar[tur[i]] - (n - i)]);
            }
        } else{
            for (auto y : ada){
                cnt[y] = 0;
            }
            ada.clear();
            mx = 0;
            for (int i=range.fi;i<=range.se;i++){
                cnt[ar[tur[i]] - (n - i)]++;
                ada.pb(ar[tur[i]] - (n - i));
                mx = max(mx, cnt[ar[tur[i]] - (n - i)]);
            }
        }
        l = range.fi, r = range.se;
        ans[node] = min(ans[node], range.se - range.fi + 1 - mx);
    }
    for (auto x : ada){
        cnt[x] = 0;
    }
    ada.clear();
    for (int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}
