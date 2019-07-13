#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n,m,k;
int p[N], s[N], c[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)cin >> p[i];
    for(int i=1;i<=n;i++)cin >> c[i];

    vector<int> v(m+1,-1);

    for(int i=1;i<=n;i++){
        v[c[i]] = max(v[c[i]], p[i]);
    }

    int ans = 0;
    for(int i=1;i<=k;i++){
        int x; cin >> x;
        if(p[x] != v[c[x]]){
            ans++;
        }
    }

    cout << ans << "\n";


    return 0;
}
