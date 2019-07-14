#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,q;
int par[N], sz[N];

int find(int x){
    return (par[x] == x ? x : par[x] = find(par[x]));
}

void merge(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa != pb){
        if(sz[pa] < sz[pb])swap(pa,pb);
        sz[pa] += sz[pb];
        par[pb] = pa;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    while(q--){
        int t,u,v;
        cin >> t >> u >> v;
        if(t == 1){
            merge(u,v);
        }else if(t == 2){
            cout << sz[find(u)] << '\n';
        }
    }


    return 0;
}
