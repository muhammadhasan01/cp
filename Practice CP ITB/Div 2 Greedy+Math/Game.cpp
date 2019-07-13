#include <bits/stdc++.h>
using namespace std;

#define p 1000000007

long long powermod(long long x, long long y){
    long long res = 1;
    x = x%p;
    while(y>0){
        if(y&1){
            res = (res*x)%p;
        }
        y /= 2;
        x = (x*x)%p;
    }
    return res%p;
}

long long answer(long long x, long long y, int k){
    if((x+y)%2 == 1 && k == -1){
        return 0;
    }
    if(x == 1 || y == 1){
        return 1;
    }
    return powermod(powermod(2,(x-1)),y-1)%p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N,M,K;
    cin >> N >> M >> K;
    cout << answer(N,M,K) << "\n";
    return 0;
}
