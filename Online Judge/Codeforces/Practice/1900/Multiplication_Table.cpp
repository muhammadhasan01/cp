#include<bits/stdc++.h>
using namespace std;

long long n,m,k;

bool can(long long x){
    long long res = 0;
    for(int i=1;i<=n;i++){
        res += min((x-1)/i,m);
    }
    return res < k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    long long l = 1, r = (long long)n*m, ans;
    while(l <= r){
        long long m = (l+r)>>1;
        if(can(m)){
            l = m+1;
            ans = m;
        }else{
            r = m-1;
        }
    }
    cout << ans << '\n';

    return 0;
}
