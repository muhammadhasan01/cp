#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<(int)n;i++)
#define forn(n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 100*1000;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n--){
        int k;cin>>k;
        ll a[NMAX+3];
        forn(k)cin>>a[i];
        ll best = inf;
        forn(k){best = min(best,a[i]);}
        ll ans = 0;
        forn(k){ans += a[i]-best;}
        cout << ans << "\n";
    }

    return 0;
}
