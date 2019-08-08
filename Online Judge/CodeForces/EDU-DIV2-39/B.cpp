#include<bits/stdc++.h>
using namespace std;

long long n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while(true){
        if(n == 0 || m == 0)break;
        if(n >= 2*m){
            n %= 2*m;
        }else if(m >= 2*n){
            m %= 2*n;
        }else{
            break;
        }
    }
    cout << n << " " << m << '\n';

    return 0;
}
