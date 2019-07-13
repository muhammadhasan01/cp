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

const int N = 3e3+5;
int n;
pll a[N];
pll dp[N][4];
ll ans = 1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n)cin >> a[i].ff;
    forn(i,1,n)cin >> a[i].ss;

    ll c = ans;

    forn(i,1,n){
        forn(j,1,3){
            dp[i][j] = {1e18,1e18};
        }
    }

    //cerr << c << "\n";

    forn(i,1,n){
        if(i == 1){
            dp[i][1] = a[i];
        }else if(i == 2){
            dp[i][1] = a[i];
            if(a[i].ff > dp[i-1][1].ff){
                dp[i][2].ff = a[i].ff;
                dp[i][2].ss = dp[i-1][1].ss + a[i].ss;
            }
        }else if(i >= 3){
            dp[i][1] = a[i];
            for(int j=i-1;j>=1;j--){
                if(a[i].ff > dp[j][1].ff){
                    dp[i][2].ff = a[i].ff;
                    dp[i][2].ss = min(dp[i][2].ss, dp[j][1].ss + a[i].ss);
                }
            }
            for(int j=i-1;j>=1;j--){
                if(a[i].ff > dp[j][2].ff){
                    dp[i][3].ff = a[i].ff;
                    dp[i][3].ss = min(dp[i][3].ss, dp[j][2].ss + a[i].ss);
                }
            }
        }
    }

    forn(i,1,n){
        //cerr << i << " => " << dp[i][3].ss << "\n";
        ans = min(ans, dp[i][3].ss);
    }

    if(ans == c)ans = -1;

    cout << ans << "\n";





    return 0;
}
