#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;

const int N = 1e5+5;
const int M = 1e9+7;
const long long inf = 1e17;
int n,m;
vector<pll> g[N];
long long dp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<long long> diss(n+3,inf);
    diss[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        int cur = pq.top().second;
        pq.pop();
        for(auto e:g[cur]){
            int u = e.first;
            long long w = e.second;
            if(diss[u] > diss[cur] + w){
                diss[u] = diss[cur] + w;
                pq.push({diss[u],u});
            }
        }
    }
    long long dist = diss[n];
    vector<bool> vis(n+3,false);
    pq.push({0,n});
    dp[n] = 1;
    vis[n] = 1;
    while(!pq.empty()){
        long long wu = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(auto e:g[u]){
            int v = e.first;
            long long wv = e.second;
            if(diss[v] + wv + wu == dist){
                dp[v] += dp[u];
                dp[v] %= M;
                if(!vis[v]){
                    vis[v] = 1;
                    pq.push({wv + wu,v});
                }
            }
        }
    }
    cout << (dp[1]%M + M)%M << '\n';


    return 0;
}
