#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m,par[N],sz[N];

int find(int x){
    return (par[x] == x ? x : par[x] = find(par[x]));
}

bool merge(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px != py){
        if(sz[px] < sz[py])swap(px,py);
        par[py] = px;
        sz[px] += sz[py];
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    int pos = -1;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        if(merge(u,v) && pos == -1){
            pos = i;
        }
    }
    cout << pos << '\n';

    return 0;
}
