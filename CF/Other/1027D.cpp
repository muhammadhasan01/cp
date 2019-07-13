#include<bits/stdc++.h>
using namespace std;

const int N = 200003;
int n, vis[N], par[N];
vector<int> g[N];
long long c[N], start, last, ans = 0;

bool dfs(int v){
    vis[v] = 1;
    for(auto e:g[v]){
        if(vis[e] == 1){
            start = e;
            last = v;
            vis[v] = 2;
            return true;
        }else if(vis[e] == 0){
            par[e] = v;
            if(dfs(e)){
                vis[v] = 2;
                return true;
            }
        }
    }
    vis[v] = 2;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> c[i];
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        g[i].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(vis[i] == 0 && dfs(i)){
            //cout << start << " " << last << "\n";
            long long res = c[start];
            for(long long x = last; x != start; x = par[x]){
                cout << x << " => ";
                res = min(res, c[x]);
            }//cout << "\n";
            ans += res;
        }
    }

    cout << ans << "\n";

    return 0;
}
