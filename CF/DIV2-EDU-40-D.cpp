#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 1e3+5;
int n,m,s,t;
vector<int> g[N];
bitset<N> vis, vis2;
set<pair<int,int>> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s >> t;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(u>v)swap(u,v);
        st.insert({u,v});
    }

    int ans = 0;

    vector<int> dist(n+3);

    queue<pii> q;
    q.push({0,s});
    dist[s] = 0;
    vis[s] = 1;
    while(!q.empty()){
        int curdis = q.front().first, v = q.front().second;
        q.pop();
        for(auto e:g[v]){
            if(!vis[e]){
                vis[e] = 1;
                dist[e] = curdis+1;
                q.push({dist[e],e});
            }
        }
    }

    vector<int> dist2(n+3);

    q.push({0,t});
    dist2[t] = 0;
    vis2[t] = 1;

    while(!q.empty()){
        int curdis = q.front().first, v = q.front().second;
        q.pop();
        for(auto e:g[v]){
            if(!vis2[e]){
                vis2[e] = 1;
                dist2[e] = curdis+1;
                q.push({dist2[e],e});
            }
        }
    }

    int distance = dist[t];

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(st.find({i,j}) != st.end())continue;
            if(dist[i] + dist2[j] + 1 >= distance && dist2[i] + dist[j] + 1 >= distance){
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
