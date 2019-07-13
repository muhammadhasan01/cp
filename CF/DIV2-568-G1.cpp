#include<bits/stdc++.h>
#define M 1000000007
using namespace std;

int n,t;
int p[15], g[15];
int pre[1<<15];
int dp[1<<15][3];
bitset<(1<<15)> vis[3];

// copas mastre hehe :v

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<15;i++)pre[i] = (1<<i);

    cin >> n >> t;
    for(int i=0;i<n;i++){
        cin >> p[i] >> g[i];
        g[i]--;
    }
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        dp[pre[i]][g[i]] = 1;
        q.push({pre[i],g[i]});
    }
    while(!q.empty()){
        int mask = q.front().first, last = q.front().second;
        q.pop();
        for(int i=0;i<n;i++){
            int nmask = (mask | pre[i]);
            if(nmask > mask && g[i] != last){
                dp[nmask][g[i]] += dp[mask][last];
                dp[nmask][g[i]] %= M;
                if(!vis[g[i]][nmask]){
                    q.push({nmask,g[i]});
                    vis[g[i]][nmask] = 1;
                }
            }
        }
    }
    long long ans = 0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<3;j++){
            int sum = 0;
            for(int k=0;k<n;k++){
                if(i & (1<<k)){
                    sum += p[k];
                }
            }
            if(sum == t){
                ans += dp[i][j];
                ans %= M;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
// typo dari tadi :(
