#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1e9+7;
const long long inf = 1e18;
int n;
long long a[N];
long long dp[N][N], pd[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n+1;i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 0 << " " << 1 << "\n";
        return 0;
    }
    n++;
    for(int i=1;i<=n-1;i++){
        dp[i][i+1] = 0;
        pd[i][i+1] = 1;
    }
    for(int j=2;j<=n-1;j++){
        for(int i=1;i<=n-j;i++){
            dp[i][i+j] = inf;
            for(int k=1;k<=j-1;k++){
                long long cur = dp[i][i+k] + dp[i+k][i+j] + a[i] * a[i+k] * a[i+j];
                if(cur < dp[i][i+j]){
                    dp[i][i+j] = cur;
                }
            }
            for(int k=1;k<=j-1;k++){
                long long cur = dp[i][i+k] + dp[i+k][i+j] + a[i] * a[i+k] * a[i+j];
                if(cur == dp[i][i+j]){
                    pd[i][i+j] += pd[i][i+k] * pd[i+k][i+j];
                    pd[i][i+j] %= M;
                }
            }
        }
    }
    cout << dp[1][n] << " " << (pd[1][n]%M + M)%M << '\n';

    return 0;
}
