#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define debug1(i) printf("debug %d\n",i);
#define debug2(i,j) printf("debug %d - %d\n",i,j);
#define debug3(i,j,k) printf("debug %d - %d - %d\n",i,j,k);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/

ll fastexp(ll x, ll y, ll p){
    ll res = 1;
    x = (x%p);
    while(y > 0){
        if(y&1){
            res = (res*x)%p;
        }
        y >>= 1;
        x = (x*x)%p;
    }
    return res;
}

ll mod_inverse(ll x, ll p){
    return fastexp(x,p-2,p)%p;
}

int nCrModPFermat(ll n,ll r,ll p){

    if(r == 0)
        return 1;

    ll fact[n+1];
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = (fact[i-1]*i)%p;
    }
    return (fact[n]*mod_inverse(fact[n-r],p)*mod_inverse(fact[r],p))%p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // p must be a prime greater than n
    cout << nCrModPFermat(12,3,13) << "\n";

    return 0;
}
