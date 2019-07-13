#include<bits/stdc++.h>
using namespace std;

long long k,n,a,b;

bool sim(long long x){
    long long temp = k;
    temp -= x*a;
    if(temp <= b)return false;
    temp -= (n-x)*b;
    if(temp <= 0)return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--){
        cin >> k >> n >> a >> b;
        long long l = 0, r = n, ans;
        while(l <= r){
            long long mid = (l+r)>>1;
            cout << l << " => " << r << " => " << mid << '\n';
            if(sim(mid)){
                l = mid+1;
                ans = mid;
            }else{
                r = mid-1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
