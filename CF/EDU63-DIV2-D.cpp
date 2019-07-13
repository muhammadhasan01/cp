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

const int N = 3e5+5;
ll n,x;
ll a[N], pre[N], le[N], ri[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    forn(i,1,n)cin >> a[i];
    forn(i,1,n)pre[i] = pre[i-1] + a[i];
    ll min_ = 0;
    forn(i,1,n){
        min_ = min(min_, pre[i]);
        le[i] = max(0ll, pre[i]-min_);
    }
    ll max_ = pre[n];
    nrof(i,n,1){
        max_ = max(max_, pre[i]);
        ri[i] = max(0ll, max_ - pre[i-1]);
    }
    ll ans = 0, temp = 0;
    forn(i,1,n){
        ans = max(ans, x * pre[i] + ri[i+1] + temp);
        ans = max(ans, le[i]);
        temp = max(temp, le[i] - x * pre[i]);
    }
    cout << ans << "\n";


    return 0;
}
