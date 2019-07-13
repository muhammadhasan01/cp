#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define ff first
#define ss second
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k,x; cin >> n >> k >> x;
    ll dp[n+2][3];
    for(int i=3;i<=n;i++){
        for(int j=1;j<=2;j++){
            if(i==3){
                if(j==1){dp[i][j]=(k-1)%MOD;}
                else{dp[i][j]=(k-2)%MOD;}
            }else{
                if(j==1){
                    dp[i][j] = ((k-1)*dp[i-1][2])%MOD;
                }else{
                    dp[i][j] = (dp[i-1][1])%MOD+((k-2)*dp[i-1][2])%MOD;
                }
            }
            //cout << i << "," << j << " => " << dp[i][j] << "\n";
        }
    }
    if(x!=1){x=2;}
    cout << dp[n][x]%MOD << "\n";
}
