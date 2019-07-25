#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, a[N];
int par[N], sz[N];
pair<int,int> p[N];
char s[N];

int find(int x){
    return (par[x] == x ? x : par[x] = find(par[x]));
}

void merge(int a, int b){
    int k1 = par[a];
    int k2 = par[b];
    if(k1 != k2){
        if(sz[k1] < sz[k2])swap(k1,k2);
        sz[k1] += sz[k2];
        par[k2] = k1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n;i++){
        p[i] = {i,i};
        par[i] = i;
        sz[i] = 1;
    }

    for(int i=1;i<=n-1;i++){
        cin >> s[i];
        if(s[i] == '1'){
            merge(i,i+1);
            int k = find(i);
            p[k].first = min(i, p[k].first);
            p[k].second = max(i+1,p[k].second);
        }
    }

    bool ok = true;
    for(int i=1;i<=n;i++){
        int k = find(i);
        ok &= (p[k].first <= a[i] && a[i] <= p[k].second);
    }

    puts(ok ? "YES" : "NO");

    return 0;
}
