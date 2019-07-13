#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k;

ll adaGak(ll v1[], vector<ll> v2, ll i){
    ll penentu = v1[i];
    for(ll j = 0; j < v2.size(); j++){
        ll p = lower_bound(v1,v1+n,v2[j]-penentu)-v1;
        if(v1[p] == v2[j]-penentu){
            if(p == i){
                if(i+1 < n){
                if(v1[p+1] == v1[p]){return 0;}else{continue;}}
                else{continue;}
            }else{
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    ll v1[n];
    for(ll i = 0; i < n; i++){
        cin >> v1[i];
    }
    if(n==1){
        cout << "1\n";
        return 0;
    }
    sort(v1,v1+n);
    ll bs = v1[n-1]+v1[n-2];
    vector<ll> v2;
    ll x = 2;//cout << "\n";
    while(x <= bs){
        //cout << x << " ";
        v2.push_back(x);
        x *= 2;
    }//cout << "\n\n";
    ll banyakMin = 0;
    for(ll i = 0; i < n; i++){
        banyakMin += adaGak(v1,v2,i);
    }
    cout << banyakMin << "\n";
    return 0;
}
