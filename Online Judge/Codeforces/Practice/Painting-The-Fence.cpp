#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+6;
int n,q;
pair<int,int> p[N];
int f[N],dp[N],pd[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i=1;i<=q;i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p+1,p+1+q);
    for(int i=1;i<=q;i++){
        f[p[i].first]++;
        f[p[i].second + 1]--;
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        f[i] += f[i-1];
        dp[i] = dp[i-1];
        pd[i] = pd[i-1];
        if(f[i] > 0)res++;
        if(f[i] == 1)dp[i]++;
        if(f[i] == 2)pd[i]++;
    }
    f[n+1] = 0;
    int ans = 0;
    for(int i=1;i<=q;i++){
        for(int j=i+1;j<=q;j++){
            int dif = dp[p[i].second] - dp[p[i].first-1] + dp[p[j].second] - dp[p[j].first-1];
            if(p[i].second >= p[j].first){
                dif += pd[min(p[i].second,p[j].second)] - pd[p[j].first - 1];
            }
            ans = max(ans, res - dif);
        }
    }
    cout << ans << "\n";

    return 0;
}
