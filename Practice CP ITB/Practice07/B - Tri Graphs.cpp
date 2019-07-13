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

const int M = 100*1000;
ll a[M+2][4];
ll dp[M+2][4];
int vis[M+2][4];

ll ans(ll i, ll j, ll k){
    //cout << i << "," << j << "\n";
    if(vis[i][j]!=-1){return dp[i][j];}
    else if(j==1){
        if(i==k){
            return a[i][j]+a[i][j+1];
        }
        dp[i][j] = min(ans(i+1,j,k),min(ans(i+1,j+1,k),ans(i,j+1,k)))+a[i][j];
        vis[i][j] = 1;
        return dp[i][j];
    }else if(j==2){
        if(i==k){
            return a[i][j];
        }else if(i+1==k){
            dp[i][j] = min(min(ans(i,j+1,k),ans(i+1,j-1,k)),ans(i+1,j,k))+a[i][j];
            vis[i][j] = 1;
            return dp[i][j];
        }else{
            vis[i][j] = 1;
            dp[i][j] = min(min(ans(i,j+1,k),ans(i+1,j-1,k)),min(ans(i+1,j,k),ans(i+1,j+1,k)))+a[i][j];
            return dp[i][j];
        }
    }else if(j==3){
        if(i+1==k){
            return a[i][j]+a[k][2];
        }
        dp[i][j] =  min(ans(i+1,j-1,k)+a[i][j],ans(i+1,j,k)+a[i][j]);
        vis[i][j] = 1;
        return dp[i][j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll c = 1;
    while(1==1){
    ll N; cin >> N;
    if(N==0)break;
    for(ll i=1; i<=N;i++){
        for(ll j=1; j<=3; j++){
            cin >> a[i][j];
            vis[i][j] = -1;
        }
    }
    /*for(ll i=1;i<=N;i++){
        for(ll j=1;j<=3;j++){
            cout << a[i][j] << " ";
        }cout << "\n";
    }*/

    cout << c << ". " << ans(1,2,N) << "\n";
    c++;
    }
    return 0;
}
