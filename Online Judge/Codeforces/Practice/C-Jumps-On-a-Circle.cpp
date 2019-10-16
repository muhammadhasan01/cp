#include<bits/stdc++.h>
using namespace std;

const int N = 2e7+10;
long long p,n;
bitset<N> vis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> p >> n;
    long long sum = 0, ans = 1;
    vis[sum] = 1;
    for(long long i=1;i<=min(4*p,n);i++){
        sum += i;
        sum %= p;
        if(!vis[sum]){
            vis[sum] = 1; ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}
