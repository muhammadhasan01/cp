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

ll n,h,k;

bool can(ll x){
    k = min(x,h);
    ll tmp = x*x - k*(k-1)/2;
    return (tmp <= n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h;
    ll l = 1, r = 2e9, s;
    while(l<=r){
        ll m = (l+r)/2;
        if(can(m)){
            s = m;
            l = m+1;
        }else{
            r = m-1;
        }
    }

    k = min(h,s);
    ll c = s*s - k*(k-1)/2;
    ll lx = (2 * s - 1) - (k - 1);
    n -= c;
    cout << lx + (n + s - 1)/s << "\n";




    return 0;
}
