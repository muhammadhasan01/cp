#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+5;
int n,m;
int out[N];

int dist(int u, int v){
    return v-u + n * (u > v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> min_dist(n+1,(int)1e6);
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        out[u]++;
        min_dist[u] = min(min_dist[u], dist(u,v));
    }

    for(int s=1;s<=n;s++){
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(out[i] > 0){
                ans = max(ans, dist(s,i) + n * (out[i] - 1) + min_dist[i]);
            }
        }
        cout << ans << " ";
    }



    return 0;
}
