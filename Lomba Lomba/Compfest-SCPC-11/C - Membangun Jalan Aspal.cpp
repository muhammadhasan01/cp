#include<bits/stdc++.h>
using namespace std;
typedef pair<int,long long> pil;

const int N = 2e5+5;
const int L = log2(N);
int n,q;
vector<pil> g[N];
long long dist[N];
int par[N], up[N][L+5], tin[N], tout[N], rap[N], tim;
bitset<N> mark;

void dfs(int u, int p, long long d){
    par[u] = p;
    dist[u] = d;
    tin[u] = ++tim;
    for(int i=1;i<=L;i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for(auto e:g[u]){
        if(e.first != p){
            dfs(e.first,u,e.second);
        }
    }
    tout[u] = ++tim;
}

bool is_anc(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v){
    if(is_anc(u,v)){
        return u;
    }
    if(is_anc(v,u)){
        return v;
    }
    for(int i=L;i>=0;i--){
        if(!is_anc(up[u][i],v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

int find(int x){
    return (rap[x] == x ? x : find(rap[x]));
}

long long answer(int u, int v){
    long long ret = 0;
    int k = lca(u,v);
    if(k == u || k == v){
        if(k == v)swap(u,v);
        ret = dist[u] - dist[v];
        for(int x=v;;x=par[x]){
            if(x == k)break;
            if(mark[x]){
                int p = x;
                x = find(x);
                int q = x;
                ret -= dist[p] - dist[q];
            }else{
                mark[x] = 1;
                rap[x] = par[x];
            }
        }
    }else{
        ret = dist[u] + dist[v] - dist[k];
        for(int x=u;;x=par[x]){
            if(x == k)break;
            if(mark[x]){
                int p = x;
                x = find(x);
                int q = x;
                ret -= dist[p] - dist[q];
            }else{
                mark[x] = 1;
                rap[x] = par[x];
            }
        }
        for(int x=v;;x=par[x]){
            if(x == k)break;
            if(mark[x]){
                int p = x;
                x = find(x);
                int q = x;
                ret -= dist[p] - dist[q];
            }else{
                mark[x] = 1;
                rap[x] = par[x];
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for(int i=1;i<=n-1;i++){
        int u,v;
        long long w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++){
        rap[i] = i;
    }

    dfs(1,1,0);

    cin >> q;
    while(q--){
        int u,v;
        cin >> u >> v;
        cout << answer(u,v) << '\n';
    }

    return 0;
}
