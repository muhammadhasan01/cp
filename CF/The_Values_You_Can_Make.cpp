#include<bits/stdc++.h>
using namespace std;

const int N = 503;
const int M = N * N;
int n,k;
int c[N];
bool dp[3][N][N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        int cur = i % 2;
        int last = 1 - cur;
        int x; cin >> x;
        for(int j=0;j<=k;j++){
            for(int y=0;y<=k;y++){
                dp[cur][j][y] = dp[last][j][y];
                if(j >= x){
                    dp[cur][j][y] |= dp[last][j - x][y];
                    if(y >= x){
                        dp[cur][j][y] |= dp[last][j-x][y-x];
                    }
                }
            }
        }
    }

    vector<int> ans(k+3);
    int len = 0;
    for(int i=0;i<=k;i++){
        if(dp[n%2][k][i])
            ans[++len] = i;
    }
    cout << len << '\n';
    for(int i=1;i<=len;i++)cout << ans[i] << (i == len ? '\n' : ' ');


    return 0;
}
