#include<bits/stdc++.h>
using namespace std;

struct E{
    int u,v;
    long long w;
};

const int N = 1e5+5;
int n,m;
vector<E> edge;
int par[N];

bool cmpr(E a, E b){
    return a.w < b.w;
}

int find(int x){
    return (par[x] == x ? x : par[x] = find(par[x]));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    edge.resize(m);
    for(int i=1;i<=n;i++)par[i] = i;
    for(int i=0;i<m;i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge.begin(),edge.end(),cmpr);
    long long cost = 0;
    int cnt = 0;
    for(int i=0;i<m;i++){
        int pu = find(edge[i].u);
        int pv = find(edge[i].v);
        if(pu != pv){
            cost += edge[i].w;
            cnt++;
            par[pv] = pu;
            if(cnt == n-1)break;
        }
    }
    cout << cost << '\n';

    return 0;
}
