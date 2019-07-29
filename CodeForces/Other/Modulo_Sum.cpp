#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
const int M = 1e3+5;
int n,m;
int a[N];
bitset<M> dp[M];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    if(n > m){
        puts("YES");
        return 0;
    }

    dp[1][a[1]%m] = 1;
    for(int i=2;i<=n;i++){
        dp[i][a[i]%m] = 1;
        for(int j=0;j<m;j++){
            if(dp[i-1][j]){
                dp[i][j] = 1;
                dp[i][(j + a[i])%m] = 1;
            }
        }
    }
    puts(dp[n][0] ? "YES" : "NO");

    return 0;
}
