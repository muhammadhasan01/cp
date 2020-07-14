#include<bits/stdc++.h>
using namespace std;

int tc, n, b[100003], dp[100003][2];

int solve(){
    if(n == 1)return b[1];
    dp[1][0] = 0, dp[1][1] = 0;
    for(int i=2;i<=n;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + abs(b[i-1]-1));
        dp[i][1] = max(dp[i-1][0] + abs(b[i]-1), dp[i-1][1] + abs(b[i]-b[i-1]));
    }
    return max(dp[n][0],dp[n][1]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++)cin >> b[i];
        cout << solve() << "\n";
    }
    return 0;
}
