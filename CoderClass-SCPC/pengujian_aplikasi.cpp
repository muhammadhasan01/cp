#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pll;

const int N = 405;
const long long inf = 1e18;
int n,m,q;
vector<pll> g[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for(int i=1;i<=m;i++){
        int u,v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    vector<vector<long long>> dist(n+3,vector<long long>(n+3,inf));
    vector<vector<int>> par(n+3,vector<int>(n+3,-1));
    for(int i=1;i<=n;i++){
        dist[i][i] = 0;
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        pq.push({dist[i][i],i});
        par[i][i] = i;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto e:g[u]){
                int v = e.first;
                long long w = e.second;
                if(dist[i][v] > dist[i][u] + w){
                    dist[i][v] = dist[i][u] + w;
                    par[i][v] = u;
                    pq.push({dist[i][v],v});
                }
            }
        }
    }


    vector<int> ans(n+3);
    while(q--){
        int l,r;
        cin >> l >> r;
        int len = 0;
        for(int i=l;;i=par[r][i]){
            cout << i << (i == r ? '\n' : ' ');
            if(i == r)break;
        }
    }


    return 0;
}
