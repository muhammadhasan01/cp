#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int M = 1e6+5;
int n, a[N];
bitset<M> vis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        vis[a[i]] = 1;
    }
    sort(a+1,a+1+n);
    int ans = 0;
    for(int i=2;i<=M;i++){
        if(!vis[i])continue;
        for(int j=2*i;j<=2*M;j+=i){
            int pos = lower_bound(a+1,a+1+n,j) - a - 1;
            if(pos == 0)continue;
            ans = max(ans, a[pos]%i);
            if(pos == n)break;
        }
    }
    cout << ans << '\n';


    return 0;
}
