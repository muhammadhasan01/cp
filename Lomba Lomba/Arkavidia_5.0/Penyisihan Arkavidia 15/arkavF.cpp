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
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int tc;
int n,q,m;
ll dp[1003];
pll a[1003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n >> q;
        forn(i,1,n)cin >> a[i].ff >> a[i].ss;
        forn(i,1,1000){
            dp[i] = inf;
            forn(j,1,n){
                if(a[j].ff <= i){
                    dp[i] = min(dp[i], dp[i - a[j].ff] + a[j].ss);
                }
            }
        }
        forn(i,1,q){
            cin >> m;
            cout << dp[m] << "\n";
        }
    }
    return 0;
}
