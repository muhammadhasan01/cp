#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
long long pre[N], dp[N];
int n;
long long m,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        long long x; cin >> x;
        pre[i] = x + (i == 0 ? 0 : pre[i-1]);
    }

    long long res = 0;
    for(int s=1;s<=m && s<=n;s++){
        res = max(res, pre[s-1] - k);
    }
    for(int i=0;i<n;i++){
        if(i+1 >= m){
            long long cur = pre[i] - (i-m>=0)*pre[i-m] - k;
            cur += (i-m>=0)*dp[i-m];
            dp[i] = max(dp[i], + cur);
        }

        for(int s=0; s<m && i+s<n ;s++){
            res = max(res, dp[i] + pre[i+s] - pre[i] - k * (s > 0));
        }
    }

    cout << res << '\n';

    return 0;
}
