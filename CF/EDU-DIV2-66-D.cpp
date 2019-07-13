#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 3e5+10;
ll n,k,a[N],erp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    cin >> n >> k;
    forn(i,1,n)cin >> a[i];
    nrof(i,n,1){
        if(i == n)erp[i] = a[i];
        else erp[i] = erp[i+1] + a[i];
    }

    vector<ll> v;
    forn(i,2,n)v.pb(erp[i]);

    sort(all(v),greater<ll>());

    ll ans = erp[1];
    forn(i,0,k-2)ans += v[i];
    cout << ans << "\n";







    return 0;
}
