#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 200000;
int n;
pair<ll,ll> a[N+2];
ll mid, temp;

bool ctm(pll a, pll b){
    return a.second - a.first < b.second - b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1,a+n+1,ctm);
    ll l = 1; ll r = 1234567891012134;
    /*cout << "\n";
    for(int i=1;i<=n;i++){
      cout << a[i].first << " " << a[i].second << "\n";
    }cout << "\n";*/
    while(l<=r){
        //cout << l << "," << r << " => ";
        mid = (l+r)/2;
        //cout << mid << "\n";
        if(mid == l || mid == r){break;}
        temp = mid;
        bool y = true;
        for(int i=1;i<=n;i++){
          if(temp < a[i].first){
            y = false; break;
          }
          temp-= a[i].second;
        }
        if(temp < 0){y = false;}
        if(y){
          r = mid;
        }else{
          l = mid;
        }
    }
    cout << mid << "\n";
    return 0;
}
