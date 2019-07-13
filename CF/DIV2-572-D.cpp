#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
vector<int> g[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool not_ok = false;
    for(int i=1;i<=n;i++){
        not_ok |= ((int)g[i].size() == 2);
    }
    cout << (not_ok ? "NO" : "YES") << "\n";

    return 0;
}
