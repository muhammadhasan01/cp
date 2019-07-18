#include<bits/stdc++.h>
using namespace std;

const int N = 205;
const int M = 1e5+5;
bitset<M> dp[N];
int a[N];
char c[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        int m = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            m += a[i];
        }
        for(int j=0;j<=m;j++){
            for(int i=0;i<=n;i++){
                if(j == 0){
                   dp[i][j] = 1;
                }else if(i == 0){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 0;
                    if(dp[i-1][j] == 1)dp[i][j] = 1;
                    if(j >= a[i] && dp[i-1][j - a[i]] == 1){
                        dp[i][j] = 1;
                    }
                }
            }
        }
        long long ans = 0;
        int pos = 0;
        for(int i=0;i<=m/2;i++){
            long long k = (long long)i * (long long)(m-i);
            if(k > ans && dp[n][i] == 1){
                ans = k;
                pos = i;
            }
        }
        cout << ans << '\n';
        for(int i=n;i>=1;i--){
            if(a[i] <= pos && dp[i-1][pos - a[i]] == 1){
                c[i] = 'D';
                pos -= a[i];
            }else{
                c[i] = 'R';
            }
        }
        for(int i=1;i<=n;i++)cout << c[i];
        cout << '\n';
    }
}
