#include<bits/stdc++.h>
using namespace std;

long long n,k;

bool can(long long x){
    long long res = x * (x+1)/2 - (n - x);
    return res >= k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    long long l = 0, r = n, ans;
    while(l <= r){
        long long mid = (l+r)>>1;
        if(can(mid)){
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << n - ans << '\n';

    return 0;
}
