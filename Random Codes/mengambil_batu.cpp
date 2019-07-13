#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const long long inf = 1e18;
int n,m;
int w[105], v[105];
long long dp[3][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> w[i];
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        res += v[i];
    }

    int ans = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=res;j++){
            if(j == 0){
                dp[(i&1)][j] = 0;
            }else if(i == 0){
                dp[(i&1)][j] = inf;
            }else{
                dp[(i&1)][j] = dp[!(i&1)][j];
                if(v[i] <= j){
                    dp[(i&1)][j] = min(dp[(i&1)][j], w[i] + dp[!(i&1)][j - v[i]]);
                }
                if(dp[(i&1)][j] <= m){
                    ans = j;
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
