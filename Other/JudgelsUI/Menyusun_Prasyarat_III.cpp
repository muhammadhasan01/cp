#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
deque<int> st;
vector<int> g[N];
int sz[N], tr[N];
vector<vector<int>> ans;
int col[N];
bool ok = true;

void dfs(int u){
    col[u] = 1;
    for(auto e:g[u]){
        if(col[e] == 0){
            dfs(e);
        }else if(col[e] == 1){
            ok = false;
        }
    }
    col[u] = 2;
    st.push_front(u);
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

    int len = st.size();
    if(ok){

    }else{
        for(int i=1;i<=len;i++){
            cout << -1 << (i == len ? '\n' : ' ');
        }
    }


    return 0;
}
