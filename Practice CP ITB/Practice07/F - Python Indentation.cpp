#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define formn(i,n) for(int i=0;i<=(int)n;i++)
#define debug1(i) printf("debug => %d\n",i);
#define debug2(i,j) printf("debug => %d - %d\n",i,j);
#define debug3(i,j,k) printf("debug => %d - %d - %d\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 5000;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    char c[n+3];
    forn(i,n){
        cin >> c[i];
    }
    ll dp[n+3][n+3];
    dp[1][1] = 1;
    for(int j=2;j<=n;j++){
        dp[1][j] = 0;
    }
    for(int i=2;i<=n;i++){
        ll sum = 0;
        for(int j=1;j<=n;j++){
            sum += dp[i-1][j];
        }
        for(int j=1;j<=n;j++){
            if(c[i-1] == 'f'){
                if(j == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }else{
                dp[i][j] = sum%MOD;
            }
            sum -= dp[i-1][j];
        }
    }
    ll res = 0;
    for(int i=1;i<=n;i++){
        res += dp[n][i], res %= MOD;
    }
    cout << res << "\n";
    return 0;
}
