#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,m;
vector<int> g[N];
int deg[N];

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
        for(auto e:g[i])deg[e]++;
    }

    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            q.push(i);
        }
    }

    int cnt = 0;
    vector<int> top(n+3);
    int len = 0;


    while(!q.empty()){
        int u = q.top();
        q.pop();
        top[++len] = u;
        for(auto e:g[u]){
            if(--deg[e] == 0){
                q.push(e);
            }
        }
        if(len > n){
            break;
        }
    }

    if(len == n){
        for(int i=1;i<=len;i++)cout << top[i] << (i == len ? '\n' : ' ');
    }else{
        for(int i=1;i<=n;i++)cout << -1 << (i == n ? '\n' : ' ');
    }

    return 0;
}
