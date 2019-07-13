#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll answer(ll gcd, ll C, ll D, vector<ll> v){
    if(D == gcd || C == gcd)return gcd;
    if(D == 1)return 1;
    if(C > gcd)return -1;
    vector<ll>::iterator it = upper_bound(v.begin(),v.end(),D)-1;
    if(*it >= C){
        return *it;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, B, gcd, C, D, Q;
    cin >> A >> B;
    gcd = __gcd(A,B);
    vector<ll> v;
    if(gcd!=1){
        for(ll i = 1; i*i<= gcd; i++){
            if(gcd%i==0){
                v.push_back(i);
                v.push_back(gcd/i);
            }
        }
    }
    sort(v.begin(),v.end());
    cin >> Q;
    while(Q--){
        cin >> C >> D;
        cout << answer(gcd,C,D,v) << "\n";
    }
    return 0;
}
