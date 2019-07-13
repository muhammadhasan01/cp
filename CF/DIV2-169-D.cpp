#include<bits/stdc++.h>
using namespace std;

long long a,b;

string bin(long long x){
    return (x <= 1 ? to_string(x) : bin(x/2) + bin(x%2));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> a >> b;
    if(a == b){
        puts("0");
    }else if(a+1 == b){
        cout << (a^b) << "\n";
    }else if(a+2 == b){
        long long ans = (a^(a+1));
        ans = max(ans, (a^(a+2)));
        ans = max(ans, ((a+1)^(a+2)));
        cout << ans << '\n';
    }else{
        string k = bin((a^b));
        int n = (int)k.size();
        cout << ((long long)1 << n) - 1 << '\n';
    }


    return 0;
}
