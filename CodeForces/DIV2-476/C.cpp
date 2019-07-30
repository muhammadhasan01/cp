#include<bits/stdc++.h>
using namespace std;

long long n,k,m,d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m >> d;
    long long ans = 0;
    for(long long i=1;i<=d;i++){
        long long l = 1, r = m, x = -1;
        long long cur = (i-1) * k + 1;
        while(l <= r){
            long long mid = (l+r)>>1;
            if(n/mid >= cur){
                l = mid + 1;
                x = mid;
            }else{
                r = mid - 1;
            }
        }
        if(x == -1)continue;
        if(n/x > i*k)continue;
        ans = max(ans, x * i);
    }

    cout << ans << '\n';

    return 0;
}
