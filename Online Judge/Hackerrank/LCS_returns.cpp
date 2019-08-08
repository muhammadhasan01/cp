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
#define debug1(i) printf("debug => %ld\n",i);
#define debug2(i,j) printf("debug => %ld - %ld\n",i,j);
#define debug3(i,j,k) printf("debug => %ld - %ld - %ld\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

string a,b;
vector<int> pos[5011];

int func(char c){
    if('a' <= c && c <= 'z')return c-'a';
    if('A' <= c && c <= 'Z')return c-'A';
    return c-'0'+52;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    int n = LEN(a), m = LEN(b);

    form(i,m){
        pos[func(b[i])].pb(i+1);
    }

    int dp[n+2][m+2];


    formn(i,n){
        formn(j,m){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                if(a[i-1] == b[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }

    int len = dp[n][m];

    int dpr[n+2][m+2] = {0};
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(a[i-1] == b[j-1]){
                dpr[i][j] = 1 + dpr[i+1][j+1];
            }else{
                dpr[i][j] = max(dpr[i+1][j],dpr[i][j+1]);
            }
        }
    }

    ll ans = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<62;j++){
            for(auto x:pos[j]){
                if(dp[i][x-1]+dpr[i+1][x+1] == len){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
