#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minway(ll a[], ll l, ll r){
    if(l==r)return 1;
    ll jawab = 0, pan = r-l+1, banyak = 0;
    ll left = l, right = r;
    ll x = *min_element(a+l,a+r+1);
    if(x >= pan){
        return pan;
    }
    for(ll i = l; i <= r; i++){
        a[i]-=x;
        if(a[i] == 0){
            banyak++;
        }
    }
    jawab += x;
    if(banyak == pan){
        return x;
    }
    for(ll i = l; i <= r; i++){
        if(a[i]==0){
            if(i==l){left = i+1;}
            if(i!=l){
            right = i-1;
            jawab += minway(a,left,right);
            left = i+1;
            }
        }
    }
    jawab+=minway(a,left,r);
    return min(pan,jawab);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,kecil, answer = 0;
    cin >> N;
    ll a[N], left = 0, right = N-1;
    for(ll i = 0; i < N; i++){
        cin >> a[i];
    }
    if(N==1){
        cout << "1\n";
        return 0;
    }
    cout << minway(a,0,N-1) << "\n";
    return 0;
}
