#include<bits/stdc++.h>
using namespace std;

const int N = 2e3+5;
const int M = 1e9+7;
int n,m;
int a[N], b[N];
int store[N][N];
long long dp[N][N], pre[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=0;j--){
            store[i][j] = max(store[i][j+1], a[j]);
        }
    }

    if(m == 1){
        cout << (store[n][1] == b[m] ? 1 : 0) << '\n';
        return 0;
    }

    long long res = 0;
    for(int i=1;i<=m-1;i++){
        for(int j=i;j<=n;j++){
            if(i == 1){
                dp[i][j] = (store[j][1] == b[1] ? 1 : 0);
            }else{
                int l = i, r = j, ans = j;
                while(l <= r){
                    int mid = (l + r)/2;
                    if(store[j][mid] <= b[i]){
                        r = mid - 1;
                        ans = mid;
                    }else{
                        l = mid + 1;
                    }
                }
                l = i, r = j;
                int ans2 = j;
                while(l <= r){
                    int mid = (l + r)/2;
                    if(store[j][mid] >= b[i]){
                        l = mid + 1;
                        ans2 = mid;
                    }else{
                        r = mid - 1;
                    }
                }
                if(store[j][ans] == b[i])dp[i][j] = pre[i-1][ans2-1] - pre[i-1][ans - 2];
                dp[i][j] %= M;
            }
            pre[i][j] = pre[i][j-1] + dp[i][j];
            pre[i][j] %= M;
            if(i == m-1 && store[n][j+1] == b[m]){
                res += dp[i][j];
                res %= M;
            }
        }
    }
    cout << (res%M + M)%M << '\n';


    return 0;
}
