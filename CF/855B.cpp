#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define formn(i,n) for(int i=0;i<=(int)n;i++)
#define debug1(i) printf("debug => %lld\n",i);
#define debug2(i,j) printf("debug => %lld - %lld\n",i,j);
#define debug3(i,j,k) printf("debug => %lld - %lld - %lld\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

struct s{
    ll x,y,z;
};

ll n,p,q,r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> p >> q >> r;
    ll a[n+1];
    forn(i,n)cin>>a[i];
    s dp;
    for(int i=1;i<=n;i++){
        if(i == 1){
            dp.x = a[i]*(p+q+r);
            dp.y = a[i]*(p+q);
            dp.z = a[i]*p;
        }else{
            dp.x = max(dp.x,a[i]*(p+q+r));
            dp.x = max(dp.x,dp.y+a[i]*r);
            dp.x = max(dp.x,dp.z+a[i]*(q+r));
            dp.y = max(dp.y,a[i]*(p+q));
            dp.y = max(dp.y,dp.z+a[i]*q);
            dp.z = max(dp.z,a[i]*p);
        }
    }
    cout << dp.x << "\n";
    return 0;
}
