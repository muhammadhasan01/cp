#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pll;

const int N = 1e5+5;
const long long inf = 1e18;
int n,m;
vector<pll> g[N];

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
    vector<long long> dist(n+3, inf);
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto e:g[u]){
            int v = e.first;
            long long w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    cout << dist[n] << '\n';

    return 0;
}
