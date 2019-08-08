#include<bits/stdc++.h>
using namespace std;

long long n;

bool isPrime(long long k){
    for(long long i=2;i*i<=k;i++){
        if(k % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if(n == 2){
        puts("1");
    }else if(n % 2 == 0){
        puts("2");
    }else if(isPrime(n)){
        puts("1");
    }else if(isPrime(n-2)){
        puts("2");
    }else{
        puts("3");
    }


    return 0;
}
