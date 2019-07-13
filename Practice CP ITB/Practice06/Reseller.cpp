#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    ll v[n+2], w[n+2], valw[m+2], maxw[m+2];
    for(ll i=0;i<n;i++)cin>>v[i];
    for(ll i=0;i<n;i++)cin>>w[i];
    for(ll i=0;i<m;i++)cin>>valw[i];
    for(ll i=0;i<m;i++)cin>>maxw[i];
    ll W = *max_element(maxw,maxw+m);
    ll dp[n+2][W+2];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else if(w[i-1] <= j){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
            //cout << "(" << i  << "," << j << ") =>" << dp[i][j] << "\n";
        }
    }
    ll best = -1;
    for(ll i=0;i<m;i++){
        best = max(best,dp[n][maxw[i]]-valw[i]);
    }
    cout << best << "\n";
    return 0;
}
