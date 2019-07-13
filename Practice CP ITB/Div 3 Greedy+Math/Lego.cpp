#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll answer(ll a, ll b, ll c){
  ll x,y;
  if(abs(a) > abs(b)){
    x = abs(a);
    y = abs(b);
  }else{
    x = abs(b);
    y = abs(a);
  }
  if(c < x){
    return -1;
  }else if(c == x){
    if(y == 0){
      ll ans = x/2;
      return 2*ans;
    }else{
      return y+answer(x-y,0,c-y);
    }
  }else{
    ll k = answer(x,y,x);
    if(k == x){
      if((c-k)%2 == 0){
        return c;
      }else{
        return c-2;
      }
    }else{
      return c-1;
    }
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,x,y,a,b,k;
    cin >> n;
    while(n--){
    cin >> x >> y >> a >> b >> k;
    cout << answer(a-x,b-y,k) << "\n";
    }
    return 0;
}
