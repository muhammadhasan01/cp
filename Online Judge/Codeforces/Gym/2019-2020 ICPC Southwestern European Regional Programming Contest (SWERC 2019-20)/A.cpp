// author : Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1010;
const int INF = 1e9 + 10;

pii ar[N];
int cost[N];
int n;
int B, T;

vector<pii> stlink[N];
vector<pii> adj[N];
int dist[N][N];

int fdist(pii a, pii b){
    int delx = (int)(a.fi - b.fi);
    int dely = (int)(a.se - b.se);
    int ret = (int)ceil(sqrt(delx * delx + dely * dely));
    return ret;
}

int dp[N][N]; // jarak terlewati, ampe mana
void solve(){
    for (int i=0;i<=B;i++){
        fill(dp[i], dp[i] + N, INF);
    }
    dp[0][0] = 0;
    set<pair<int, pii>> setdah;
    setdah.insert(mp(0, mp(0, 0)));
    while (!setdah.empty()){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        int curcost = tp.fi;
        int curjarak = tp.se.fi;
        int node = tp.se.se;        
        // cout << node << " " << curjarak << " " << curcost << el;
        for (auto& x : adj[node]){
            int nnode = x.fi;
            int njarak = curjarak + dist[node][nnode];
            int ncost = curcost + x.se;

            // cout << nnode << " => " << ncost << el;
            if (njarak <= B && dp[njarak][nnode] > ncost){
                setdah.erase(mp(ncost, mp(njarak, nnode)));
                dp[njarak][nnode] = ncost;
                setdah.insert(mp(ncost, mp(njarak, nnode)));
            }
        }
    }
    int ans = INF;
    for (int i=0;i<=B;i++){
        ans = min(ans, dp[i][n + 1]);
    }
    if (ans == INF){
        cout << -1 << el;
    } else{
        cout << ans << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ar[0].fi >> ar[0].se;
    cin >> ar[N - 1].fi >> ar[N - 1].se;
    cin >> B;
    cin >> cost[0];
    cin >> T;
    for (int i=1;i<=T;i++){
        cin >> cost[i];
    }
    cin >> n;
    ar[n + 1] = ar[N - 1];
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        int len;
        cin >> len;
        for (int j=0;j<len;j++){
            int tar, m;
            cin >> tar >> m;
            stlink[i].pb(mp(tar + 1, m));
        }
    }
    for (int i=0;i<=n + 1;i++){
        for (int j=0;j<=n + 1;j++){
            dist[i][j] = fdist(ar[i], ar[j]);
        }
    }
    adj[0].pb(mp(n + 1, dist[0][n + 1] * cost[0]));
    for (int i=1;i<=n;i++){
        adj[0].pb(mp(i, dist[0][i] * cost[0]));
        adj[i].pb(mp(n + 1, dist[i][n + 1] * cost[0]));
        for (auto& x : stlink[i]){
            int j = x.fi;
            int m = x.se;
            auto temp = dist[i][j] * cost[m];
            adj[i].pb(mp(j, temp));
            adj[j].pb(mp(i, temp));
        }
    }
    solve();

    return 0;
}