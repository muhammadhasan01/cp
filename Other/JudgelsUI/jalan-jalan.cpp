#include<bits/stdc++.h>
using namespace std;

// credits to : https://github.com/luqmanarifin/cp

const int N = 205;
const int M = 1e5+5;
bitset<M> dp[N];
int a[N];
char c[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    scanf("%d", &tc);
    while(tc--){
        int n;
        scanf("%d", &n);
        long long m = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", a+i);
            m += a[i];
        }
        int tgt = m/2;
        for(int j=0;j<=tgt;j++){
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
        int pos = 0;
        for(int i=tgt;i>=0;i--){
            if(dp[n][i]){
                pos = i;
                break;
            }
        }
        long long t = pos;
        printf("%lld\n", t * (m-t));
        for(int i=n;i>=1;i--){
            if(a[i] <= pos && dp[i-1][pos - a[i]] == 1){
                c[i-1] = 'D';
                pos -= a[i];
            }else{
                c[i-1] = 'R';
            }
        }
        c[n] = '\0';
        printf("%s\n",c);
    }
}
