#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,k,m;
map<string,int> f;
string s[N];
long long a[N], cost;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        f[s[i]] = i;
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=k;i++){
        int sz; cin >> sz;
        long long mini = 1e18;
        vector<int> v(sz);
        for(int j=0;j<sz;j++){
            cin >> v[j];
            mini = min(mini,a[v[j]]);
        }
        for(auto e:v){
            a[e] = mini;
        }
    }
    for(int i=1;i<=m;i++){
        string k;cin>>k;
        cost += a[f[k]];
    }
    cout << cost << "\n";

    return 0;
}
