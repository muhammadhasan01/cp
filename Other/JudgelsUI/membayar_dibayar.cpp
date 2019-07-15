#include<bits/stdc++.h>
using namespace std;

struct E{
    int u,v;
    long long w;
};

const long long inf = 1e18;
int s,d;
int n,m;
vector<E> edge;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> d >> n >> m;
    edge.resize(m+1);
    for(int i=1;i<=m;i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    int x = -1;
    vector<long long> d(n+3,inf);
    d[s] = 0;
    for(int i=1;i<=n-1;i++){
        x = -1;
        for(auto e:edge){
            if(d[e.v] > d[e.u] + e.w){
                d[e.v] = d[e.u] + e.w;
                x = e.v;
            }
        }
    }

    puts(x != -1 ? "TIDAK" : "BISA");

    return 0;
}
