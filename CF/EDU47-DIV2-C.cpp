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

ld n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cout << fixed << setprecision(9);
    ld ans = 0;
    forn(i,1,m){
        ld x,d; cin >> x >> d;
        ans += x * n;
        if(d > 0){
            ans += d * (n-1) * n / 2; // ok
        }else if(d < 0){
            ll p = n/2; ld q = n - p;
            if((int)n&1){
                ans += d * p * (p+1);
            }else{
                ans +=  d * p * p;
            }
        }
    }
    cout << ans/n << "\n";






    return 0;
}
