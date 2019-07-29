#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int n;
pair<int,int> a[N][N];
pair<int,int> dp[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin >> x;
            int k1 = 0, k2 = 0;
            while(x % 2 == 0){
                x /= 2;
                k1++;
            }
            while(x % 5 == 0){
                x /= 5;
                k2++;
            }
            a[i][j] = {k1,k2};
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == 1){
                dp[i][j] = dp[i-1][j];
                dp[i][j].first += a[i][j].first;
                dp[i][j].second += a[i][j].second;
            }else if(j == 1){
                dp[i][j] = dp[i][j-1];
                dp[i][j].first += a[i][j].first;
                dp[i][j].second += a[i][j].second;
            }else{
                
            }
        }
    }

    return 0;
}
