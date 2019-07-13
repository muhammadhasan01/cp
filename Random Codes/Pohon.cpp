#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
vector<int> g[N];
bitset<N> vis;
int leaf = 0, height = 0;

void dfs(int u, int dis){
    vis[u] = 1;
    if((int)g[u].size() == 1 && u != 1){
        leaf++;
    }
    height = max(height, dis);
    for(auto e:g[u]){
        if(!vis[e]){
            dfs(e,dis+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n-1;i++){
        int j;
        cin >> j;
        g[i+1].push_back(j);
        g[j].push_back(i+1);
    }

    if(n == 1){
        cout << 1 << " " << 0 << "\n";
        return 0;
    }

    dfs(1,0);

    cout << leaf << " " << height << "\n";


    return 0;
}
