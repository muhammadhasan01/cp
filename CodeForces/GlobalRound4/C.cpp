#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;
long long h,w;

long long f(long long x, int y){
    long long res = 1;
    while(y > 0){
        if(y & 1){
            res = (res * x)%M;
        }
        y >>=1;
        x = (x * x)%M;
    }
    return (res%M + M)%M;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    long long ans = 4;
    ans = (ans * f(2,h-1))%M;
    ans = (ans * f(2,w-1))%M;

    cout << (ans%M + M)%M << '\n';


    return 0;
}
