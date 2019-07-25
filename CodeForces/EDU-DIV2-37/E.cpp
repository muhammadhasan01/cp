#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,m, sz;
set<int> s, a[N];

void dfs(int u){
    sz++;
    set<int> temp;
    for(auto e:s){
        if(!a[u].count(e)){
            temp.insert(e);
        }
    }
    for(auto e:temp)s.erase(e);
    for(auto e:temp)dfs(e);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }

    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
    }

    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(s.count(i)){
            s.erase(i);
            sz = 0;
            dfs(i);
            ans.push_back(sz);
        }
    }

    sort(ans.begin(),ans.end());
    int len = ans.size();
    cout << len << '\n';
    for(int i=0;i<len;i++){
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}
