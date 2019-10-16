#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+5;
int n,m,k;
long long a[N];
long long dp[3][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i=1;i<=k;i++){
        for(int j=1+m*(i-1);j<=n-m+1;j++){
            dp[(i&1)][j] = a[j+m-1] - a[j-1] + (i > 1 ? dp[!(i&1)][j-m] : 0);
            dp[(i&1)][j] = max(dp[(i&1)][j-1], dp[(i&1)][j]);
        }
    }
    cout << dp[k&1][n-m+1] << "\n";

    return 0;
}
