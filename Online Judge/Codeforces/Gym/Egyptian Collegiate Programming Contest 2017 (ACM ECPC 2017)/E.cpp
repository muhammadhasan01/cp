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

const int N = 1e5 + 10;

int q;
int n;
vector<pil> adj[N];
bool isprime[N];
vector<int> primes;

ll ans;

bool prime2(ll a){
    for (auto& x : primes){
        if (1LL * x * x > a) break;
        if (a % x == 0){
            ll b = a / x;
            if (b >= N) return 0;
            if (isprime[b] && b != x) return 1;
            else return 0;
        }
    }
    return 0;
}

int dp1[N];
void dfs1(int node, int p){
    for (auto& x : adj[node]){
        if (x.fi == p) continue;
        dfs1(x.fi, node);
        if (x.se == 1){
            dp1[node] += dp1[x.fi] + 1;
        }
    }
}
void dfs1reroot(int node, int p){
    for (auto& x : adj[node]){
        if (x.fi == p) continue;
        if (x.se == 1){
            dp1[x.fi] = dp1[node];
        }
        dfs1reroot(x.fi, node);
    }
}

int par[N], tot[N];
unordered_map<int, int> cnt[N];

int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (cnt[a].size() < cnt[b].size()) swap(a, b);
    par[b] = a;
    ans += 1LL * tot[a] * tot[b];
    tot[a] += tot[b];
    for (auto& x : cnt[b]){
        ans -= 1LL * cnt[a][x.fi] * x.se;
        cnt[a][x.fi] += x.se;
    }
}
void dfs_solve(int node, int p){
    for (auto& x : adj[node]){
        if (x.fi == p) continue;
        dfs_solve(x.fi, node);
        if (x.se == 1){
            make(node, x.fi);
        } else if (isprime[x.se]){
            ans += 1LL * (tot[find(x.fi)] - cnt[find(x.fi)][x.se]) * (dp1[node] + 1); 
            ans += 1LL * (tot[find(node)] - cnt[find(node)][x.se]) * (dp1[x.fi] + 1); 
            cnt[find(node)][x.se] += dp1[x.fi] + 1;
            tot[find(node)] += dp1[x.fi] + 1;
        }
    }
    // cout << node << " => " << el;
    // for (auto& x : cnt[find(node)]){
    //     cout << x.fi << " " << x.se << el;
    // }
}
void preproc(){
    fill(isprime + 2, isprime + N, 1);
    for (int i=2;i * i<N;i++){
        if (!isprime[i]) continue;
        for (int j=i * i;j<N;j+=i){
            isprime[j] = 0;
        }
    }
    for (int i=1;i<N;i++){
        if (isprime[i]) primes.pb(i);
    }
    for (int i=1;i<N;i++){
        par[i] = i;
        tot[i] = 0;
    }
}
void reset(){
    for (int i=1;i<=n;i++){
        adj[i].clear();
        dp1[i] = 0;
        par[i] = i;
        tot[i] = 0;
        cnt[i].clear();
    }
    ans = 0;
}

void solve(){
    cin >> n;
    for (int i=1;i<n;i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    dfs1(1, 1);
    dfs1reroot(1, 1);
    for (int i=1;i<=n;i++){
        for (auto& x : adj[i]){
            if (x.fi > i && prime2(x.se)){
                ans += 1LL * (dp1[i] + 1) * (dp1[x.fi] + 1);
            }
        }
    }
    dfs_solve(1, 1);
    cout << ans << el;
    reset();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("evaluations.in", "r", stdin); 

    preproc();
    cin >> q;
    for (int i=1;i<=q;i++){
        cout << "Case " << i << ": ";
        solve(); 
    }

    return 0;
}