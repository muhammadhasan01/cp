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
    int a[n+2][m+2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    int dp[n+m+1][n+2][n+2];
    dp[1][1][1] = a[1][1];
    //cout << "\n";
    for(int i=2;i<=n+m-1;i++){
        for(int j = 1; j<=min(i,n); j++){
            for(int k = 1; k<= min(i,n); k++){
                    if(i-j+1 > m || i-k+1 > m){continue;}
                    if(j == 1 && k ==1){
                        dp[i][j][k] = dp[i-1][1][1]+a[1][i];
                    }else if(j==i && k == i){
                        dp[i][j][k] = dp[i-1][j-1][k-1]+a[i][1];
                    }else if(j == 1 && k > 1){
                        if(k==i){
                            dp[i][j][k] = dp[i-1][j][k-1]+a[1][i]+a[k][i-k+1];
                        }else{
                        dp[i][j][k] = max(dp[i-1][1][k-1],dp[i-1][1][k])+a[1][i]+a[k][i-k+1];}
                    }else if(j > 1 && k == 1){
                        if(j==i){
                            dp[i][j][k] = dp[i-1][j-1][1]+a[1][i]+a[j][i-j+1];
                        }else{
                        dp[i][j][k] = max(dp[i-1][j][1],dp[i-1][j-1][1])+a[1][i]+a[j][i-j+1];}
                    }else if(j == i && k < i){
                        dp[i][j][k] = max(dp[i-1][j-1][k],dp[i-1][j-1][k-1])+a[j][i-j+1]+a[k][i-k+1];
                    }else if(j < i && k == i){
                        dp[i][j][k] = max(dp[i-1][j][k-1],dp[i-1][j-1][k-1])+a[j][i-j+1]+a[k][i-k+1];
                    }else if(j>1 && k >1){
                        dp[i][j][k] = max(max(dp[i-1][j-1][k],dp[i-1][j][k-1]),max(dp[i-1][j-1][k-1],dp[i-1][j][k]));
                        if(j == k){
                            dp[i][j][k] += a[j][i-j+1];
                        }else{
                            dp[i][j][k] += a[j][i-j+1]+a[k][i-k+1];
                        }
                    }
                    //cout << i << "," << j << "," << k << " => " << dp[i][j][k] << "\n";
            }
        }
    }
    cout << dp[n+m-1][n][n] << "\n";
    return 0;
}
