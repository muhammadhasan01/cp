#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll answer(ll l){
  ll x,y,z,m = 0;
  if(l <= 4){
    return 0;}
  if(l<50){
    m = 10;
  }else if(l < 500){
    m = 100;
  }else if(l < 5000){
    m = 1000;
  }else if(l < 50000){
    m = 10000;
  }else if(l < 500000){
    m = 100000;
  }else if(l < 5000000){
    m = 1000000;
  }else if(l < 50000000){
    m = 10000000;
  }else if(l < 500000000){
    m = 100000000;
  }else if(l < 1000000000){
    m = 1000000000;
  }
  x = l/m, y = l%m;
    if(y == 0){
        return 5*x*x*m/10;
    }else if(0 < y && y < m/2){
        return y*(x+1)*x+(m/2-y)*x*x;
    }else if(m-1 > y && y >= m/2){
        return (y-m/2+1)*(x+1)*(x+1)+(m-y-2)*(x+1)*x+x*x;
    }else if(y == m-1){
        return (m/2-1)*(x+1)*(x+1)+x*(x+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N;
    cin >> N;
    cout << answer(N) << "\n";
    return 0;
}
