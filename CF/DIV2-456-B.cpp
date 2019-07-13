#include<bits/stdc++.h>
using namespace std;

long long n,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(k == 1){
        cout << n << '\n';
    }else{
        int kk = 0;
        while(n > 0){
            n /= 2;
            kk++;
        }
        cout << ((long long)1 << kk) - 1 << '\n';
    }

    return 0;
}
