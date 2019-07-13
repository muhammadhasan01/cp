#include<bits/stdc++.h>
using namespace std;

long long n,m,k;

long long ceil(long long n, long long k){
    if(n%k == 0)return n/k;
    return n/k+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    long long x,y;
    if(k <= n-1){
        cout << k+1 << " " << 1 << "\n";
    }else{
        k -= (n-1);
        x = k % (m - 1); if(x == 0)x = m-1;
        y = ceil(k,m-1);
        if(y%2 == 0)x = (m-1) - x + 1;
        cout << n - y + 1 << " " << x + 1 << "\n";
    }



    return 0;
}
