#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
vector<int> g[N];
int col[N];
bool ok = true;

void dfs(int u, int c){
    col[u] = c;
    for(auto e:g[u]){
        if(col[e] == 0){
            dfs(e,3-c);
        }else if(col[u] == col[e]){
            ok = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(col[i] == 0){
            dfs(i,1);
        }
    }

    puts(ok ? "YA" : "TIDAK");

    return 0;
}
