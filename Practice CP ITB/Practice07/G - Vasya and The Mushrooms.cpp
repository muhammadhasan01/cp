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

const int N = 3*100*1000;
const int J = 2;
ll n;
ll a[N+2][J+2];
ll dp[N+2];

ll iter(ll i, ll j, ll c){
    ll jawab = 0, r;
    for(int k=i; k<=n;k++){
        jawab+=a[k][j]*c;
        c++;
    }
    for(int k=n; k>=i;k--){
        if(j==1){r=2;}else{r=1;}
        jawab+=a[k][r]*c;
        c++;
    }
    dp[i] = jawab;
    return jawab;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    ll pre[2*n+2];
    pre[0] = 0;
    for(int j=1;j<=2;j++){
        for(int i=1;i<=n;i++){
            cin >> a[i][j];
            if(j==1){
                pre[i] = pre[i-1] + a[i][j];
            }
        }
    }
    ll c = n+1;
    for(int i = n; i >= 1; i--){
        pre[c] = pre[c-1]+a[i][2];
        c++;
    }
    //cout << pre[2*n] << "\n";
    ll best = -1, jawab = 0, temp;
    ll p = 2*n, q = 1, r = 2*n;
    c = 0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=2;j++){
            if(j==1){
                if(i==1){
                    dp[i] = iter(i,j,c);
                    //cout << i << " => " << dp[i] << "\n";
                    best = max(best,dp[i]);
                }else{
                    jawab -= a[i-1][j]*(c-1);
                    dp[i] = r*(pre[p]-pre[q])-dp[i-1]+2*jawab;
                    //cout << i << " => " << dp[i] << "\n";
                    r+=2, q+=2;
                    best = max(best,dp[i]);
                    jawab += a[i-1][j]*(c-1);
                }
            }
            jawab += a[i][j]*c;
            c++;}
        }else{
            for(int j=2;j>=1;j--){
            if(j==2){
                jawab -= a[i-1][j]*(c-1);
                //cout << r << "," << p << "," << q << "\n";
                //cout << r*(pre[p]-pre[q]) << "+" << 2*jawab << "\n";
                dp[i] = r*(pre[p]-pre[q])-dp[i-1]+2*jawab;
                //cout << i << " => " << dp[i] << "\n";
                r+=2, p-=2;
                best = max(best, dp[i]);
                jawab += a[i-1][j]*(c-1);
            }
            jawab += a[i][j]*c;
            c++;
            }
        }
        //cout << jawab << "\n";
    }
    cout << best << "\n";
}
