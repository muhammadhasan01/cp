#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll X=1,Y=1,N,K,M;
    cin >> N >> K >> M;
    for(long long i = N; i > N-K; i--){
        X = (X*i)%M;
    }
    for(long long i = K; i >= 1; i--){
        Y = (Y*i)%M;
    }
    while(X%Y != 0){
        X+=M;
    }
    cout << X/Y <<"\n";
    return 0;
}
