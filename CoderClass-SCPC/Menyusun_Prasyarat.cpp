#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
vector<int> g[N];
int col[N];

void dfs(int u){
    col[u] = 1;
    for(auto e:g[u]){
        if(col[e] == 0){
            dfs(e);
        }else if(col[e] == 1){
            puts("konflik");
            exit(0);
        }
    }
    col[u] = 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(col[i] == 0){
            dfs(i);
        }
    }

    puts("aman");


    return 0;
}
