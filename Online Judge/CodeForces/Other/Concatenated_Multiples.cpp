#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define forn(i,n) for(int i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const ll S = 200000+10;
const ll LOGN = 11;

ll N,K;
ll a[S];
vector<ll> rems[LOGN];
ll pw[LOGN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    forn(i,N)cin>>a[i];
    pw[0]=1;
    forn(i,LOGN-1){
        pw[i+1]=(pw[i]*10)%K;
    }
    forn(i,N){
        ll x = log10(a[i])+1;
        rems[x].pb(a[i]%K);
    }
    forn(i,LOGN){sort(rems[i].begin(),rems[i].end());}

    ll ans = 0;
    forn(i,N){
        for(ll j = 1; j < LOGN; j++){
            ll rem = (a[i]*pw[j])%K;
            ll xrem = (K-rem)%K;
            vector<ll>::iterator l,r;
            l = lower_bound(rems[j].begin(),rems[j].end(),xrem);
            r = upper_bound(rems[j].begin(),rems[j].end(),xrem);
            ans += (r-l);
            ll x = log10(a[i])+1;
            if(x == j && (rem+a[i]%K)%K==0)ans--;
        }
    }
    cout << ans << "\n";
    return 0;
}
