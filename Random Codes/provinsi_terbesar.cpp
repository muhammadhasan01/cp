#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m,par[N],sz[N];

int find(int x){
    return (par[x] == x ? x : par[x] = find(par[x]));
}

void merge(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px != py){
        if(sz[px] < sz[py])swap(px,py);
        par[py] = px;
        sz[px] += sz[py];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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
    long long ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, (long long)sz[i]);
    }
    cout << ans*ans << '\n';

    return 0;
}
