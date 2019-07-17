#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n;
long long a[N], b[N], dp[N][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }

    for(int i=1;i<=n;i++){
        if(i == 1){
            dp[i][1] = a[i];
            dp[i][2] = b[i];
        }else if(i == 2){
            dp[i][1] = a[i] + dp[i-1][2];
            dp[i][2] = b[i] + dp[i-1][1];
        }else{
            dp[i][1] = max(a[i] + dp[i-1][2], a[i] + dp[i-2][2]);
            dp[i][2] = max(b[i] + dp[i-1][1], b[i] + dp[i-2][1]);
        }
    }
    cout << max(dp[n][1],dp[n][2]) << '\n';


    return 0;
}
