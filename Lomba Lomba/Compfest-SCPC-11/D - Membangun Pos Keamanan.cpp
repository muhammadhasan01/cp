#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
int par[N],sz[N];
bitset<N> vis;

int find(int x){
    return (par[x] == x ? x : find(par[x]));
}

void merge(int u, int v){
    int k1 = find(u);
    int k2 = find(v);
    if(k1 != k2){
        if(sz[k1] < sz[k2])swap(k1,k2);
        sz[k1] += sz[k2];
        par[k2] = k1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        merge(u,v);
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        int k = find(i);
        if(!vis[k]){
            vis[k] = 1;
            ans += sz[k]/2;
        }
    }
    cout << ans << '\n';

    return 0;
}
