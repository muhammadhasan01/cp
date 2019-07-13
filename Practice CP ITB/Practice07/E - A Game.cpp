#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int a[N+2];
int dp[N+2][N+2];
int pre[N+2];
int ans = 0;

int maxi(int l, int r, int c){
  if(l == r){
    if(c%2==0){return 0;}else{return a[l];}
  }else if(l == r-1){
    if(c%2==0)return min(a[l],a[r]);
    return max(a[l],a[r]);
  }else if(dp[l][r] != -1){
    return dp[l][r];
  } else {
    int x,y,z = c;
    if(c%2==0){z=1;}
    x = maxi(l+1,r,z+1)+a[l];
    y = maxi(l,r-1,z+1)+a[r];
    dp[l][r] = max(x,y);
    if(c%2==0){dp[l][r] = pre[r]-pre[l-1]-dp[l][r];}
    return dp[l][r];}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    for(int i=1;i<=n;i++){cin >> a[i];}
    pre[0] = 0;
    pre[1] = a[1];
    for(int i=2;i<=n;i++){
      pre[i] = pre[i-1]+a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << maxi(1,n,1) << "\n";
    return 0;
}
