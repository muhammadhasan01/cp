#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<long long, long long>,int> plli;

const int N = 1e3+5;
int n,m;
long long f[N];
long long g[N];
vector<int> gr[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> f[i];
    }
    for(int i=1;i<=m;i++){
        int u,v; cin >> u >> v;
        g[u] += f[v];
        g[v] += f[u];
        gr[v].push_back(u);
        gr[u].push_back(v);
    }

    long long ans = 0;
    for(int i=1;i<=n;i++){
        long long maxi = -1;
        int pos = 0, cnt = -1;
        for(int j=1;j<=n;j++){
            if(f[j] > maxi){
                maxi = f[j];
                cnt = max(cnt, (int)gr[j].size());
                pos = j;
            }else if(f[j] == maxi && cnt < (int)gr[j].size()){
                cnt = (int)gr[j].size();
                pos = j;
            }
        }
        ans += g[pos];
        for(auto e:gr[pos]){
            g[e] -= f[pos];
        }
        f[pos] = -1;
        g[pos] = 0;
    }
    cout << ans << '\n';

    return 0;
}
