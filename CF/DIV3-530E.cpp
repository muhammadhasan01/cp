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

const int N = 2e5+5;
const int M = 998244353;
ll n;
ll a[N], b[N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        a[i] *= (i * (n+1-i));
    }
    forn(i,1,n)cin >> b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n,greater<ll>());
    ll ans = 0;
    forn(i,1,n){
        ans += ((a[i]%M) * (b[i]%M))%M;
        ans %= M;
    }
    cout << (ans%M+M)%M << "\n";


    return 0;
}
