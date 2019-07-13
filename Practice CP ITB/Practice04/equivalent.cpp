#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool equiv(ll a[], ll b[], ll r, ll d1, ll d2){
    bool x,y;
    if(r == 1){
        return a[d1] == b[d2];
    }
    for(ll i = 0; i < r; i++){
        if(a[i+d1]!=b[i+d2]){
            if(i < r/2){
            if(r%2==0){
            x = equiv(a,b,r/2,d1,d2) && equiv(a,b,r/2,d1+r/2,d2+r/2);
            y = equiv(a,b,r/2,d1,d2+r/2) && equiv(a,b,r/2,d1+r/2,d2);
            if(x || y){return true;}else{return false;}
            }else{
            x = equiv(a,b,r/2,d1,d2) && equiv(a,b,r/2+1,d1+r/2,d2+r/2);
            y = equiv(a,b,r/2,d1,d2+r/2) && equiv(a,b,r/2+1,d1+r/2,d2);
            if(x || y){return true;}else{return false;}
            }
            }else{
                if(r%2==0){
                if(equiv(a,b,r/2,d1+r/2,d2+r/2)){
                    return true;
                }else{return false;}}
                else{
                if(equiv(a,b,r/2+1,d1+r/2,d2+r/2)){
                    return true;
                }else{return false;}
                }
            }
        }
    }
    return true;
}

int main()
{
    ll N;
    cin >> N;
    ll a[N], b[N];
    for(ll i = 0; i < N; i++){cin >> a[i];}
    for(ll i = 0; i < N; i++){cin >> b[i];}
    if(equiv(a,b,N,0,0)){
        cout << "EQ\n";
    }else{
        cout << "NEQ\n";
    }
    return 0;
}
