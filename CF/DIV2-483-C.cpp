#include<bits/stdc++.h>
using namespace std;

int n;
long long p,q,b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> p >> q >> b;
        p = p%q;
        long long g = __gcd(p,q);
        q /= g;
        b = __gcd(q,b);
        while(b != 1){
            while(q%b == 0)q /= b;
            b = __gcd(q,b);
        }
        cout << (q==1 ? "Finite" : "Infinite") << "\n";
    }


    return 0;
}
