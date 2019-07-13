#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n == 1){
        puts("Ehab");
    }else if(n == 2){
        puts("Mahmoud");
    }else if(n&1){
        puts("Ehab");
    }else{
        puts("Mahmoud");
    }


    return 0;
}
