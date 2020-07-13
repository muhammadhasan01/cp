#include <bits/stdc++.h>

void fastscan(int &x)
{
    register int c = getchar();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = getchar());
    if(c=='-') {neg=1;c=getchar();}
    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<int, pii>;

const int N = 1e4 + 10, M = 30;
const int INF = 2e9;

int tc;
int n, m, s, f;

vector<pii> adj[N];
int dp[N][M];

piii mp3(int a, int b, int c){
    return mp(a, mp(b, c));
}

void init(){
    for (int i=0;i<n + 2;i++){
        adj[i].clear();
        fill(dp[i], dp[i] + M, INF);
    }
}

void solve(){
    fastscan(n), fastscan(m), fastscan(s), fastscan(f);
    init();
    for (int i=1;i<=m;i++){
        int a, b, c;
        fastscan(a), fastscan(b), fastscan(c);
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    dp[s][0] = 0;
    set<piii> setdah; // dijkstra, (dist, node, roads)
    setdah.emplace(mp3(dp[s][0], s, 0));
    
    int ans = INF;
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(setdah.begin());
        int curd = tp.fi;
        int node = tp.se.fi;
        int croad = tp.se.se;
        int dist = dp[node][croad];
        if (curd != dist) continue;
        if (dist >= ans) break;
        if (croad == M - 1) croad--;

        for (auto x : adj[node]){
            if (dp[x.fi][croad + 1] > dist + x.se){
                setdah.erase(mp3(dp[x.fi][croad + 1], x.fi, croad + 1));
                dp[x.fi][croad + 1] = dist + x.se;
                setdah.emplace(mp3(dp[x.fi][croad + 1], x.fi, croad + 1));
                if (x.fi == f){
                    if ((1 << (croad + 1)) <= dp[x.fi][croad + 1]){
                        ans = min(ans, 2 * dp[x.fi][croad + 1]);
                    } else{
                        ans = min(ans, dp[x.fi][croad + 1]);
                    }
                }
            }
        }
    }
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fastscan(tc);
    for (int cas=1;cas<=tc;cas++){
        printf("Case #%d: ", cas);
        solve();
    }

    return 0;
}