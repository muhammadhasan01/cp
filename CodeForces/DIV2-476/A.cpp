#include<bits/stdc++.h>
using namespace std;

long long k,n,s,p;

long long cl(long long a, long long b){
    return (a + b - 1)/b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n >> s >> p;
    cout << cl(k * cl(n,s), p) << '\n';

    return 0;
}
