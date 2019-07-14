#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
stack<int> st;
vector<int> g[N];
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
    st.push(u);
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

    if(ok){
        while(!st.empty()){
            cout << st.top();
            st.pop();
            cout << (st.empty() ? '\n')
        }
    }else{
        for(int i=1;i<=(int)st.size();i++){
            cout << -1 << (i == (int)st.size() ? '\n' : ' ');
        }
    }


    return 0;
}
