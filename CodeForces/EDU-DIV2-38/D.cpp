#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;

const int N = 2e5+5;
int n,m;
vector<pll> g[N];
long long a[N];
long long dist[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        long long w;
        cin >> u >> v >> w;
        w *= 2;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    set<pll> s;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        dist[i] = a[i];
        s.insert({dist[i],i});
    }

    while(!s.empty()){
        int u = s.begin() -> second;
        s.erase(s.begin());

        for(auto e:g[u]){
            int v = e.first;
            long long w = e.second;
            if(dist[v] > dist[u] + w){
                s.erase({dist[v],v});
                dist[v] = dist[u] + w;
                s.insert({dist[v],v});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << dist[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
