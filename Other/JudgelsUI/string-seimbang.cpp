#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int n;
long long dp[4*N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long long k = N;
    dp[k] = 1;
    long long ans = 0;
    for(int i=1;i<=n;i++){
        char x; cin >> x;
        if(x == '('){
            k++;
            dp[k] = 1;
        }else{
            k--; ans += dp[k]; dp[k]++;
        }
    }
    cout << ans << '\n';


    return 0;
}
