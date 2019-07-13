#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
const int M = 3e5+5;
const int inf = 1e7;
int dp[3][M];
int n,m;
int c[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j == 0){
                dp[(i&1)][j] = 0;
            }else if(i == 0){
                dp[(i&1)][j] = inf;
            }else if(c[i] <= j){
                dp[(i&1)][j] = min(dp[!(i&1)][j],1+dp[!(i&1)][j-c[i]]);
            }else{
                dp[(i&1)][j] = dp[!(i&1)][j];
            }
        }
    }
    if(dp[(n&1)][m] == inf)dp[(n&1)][m] = -1;
    cout << dp[(n&1)][m] << '\n';


    return 0;
}
