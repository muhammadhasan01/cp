#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max3(ll a, ll b,ll c){
    return max(max(a,b),c);
}

ll max4(ll a, ll b, ll c, ll d){
    return max(max(a,b),max(c,d));
}

const int N = 1e5+5;
ll a[N][5];
ll dp[5];
int tc,x;
bitset<N> sp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            sp[i] = 0; // reset
            scanf("%lld %lld %lld %lld",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
        }

        // marks special day
        for(int i=1;i<=m;i++){
            scanf("%d",&x);
            sp[x] = 1;
        }

        for(int i=1;i<=n;i++){
            if(i == 1){
                dp[1] = a[i][1];
                dp[2] = a[i][2];
                dp[3] = a[i][3];
                dp[4] = a[i][4];
            }else if(i > 1){
                ll t1,t2,t3,t4;
                if(sp[i-1] == 1){
                    t1 = 2*a[i][1] + dp[1];
                    t1 = max(t1, a[i][1] + max3(dp[2],dp[3],dp[4]));
                    t2 = 2*a[i][2] + dp[2];
                    t2 = max(t2, a[i][2] + max3(dp[1],dp[3],dp[4]));
                    t3 = 2*a[i][3] + dp[3];
                    t3 = max(t3, a[i][3] + max3(dp[1],dp[2],dp[4]));
                    t4 = 2*a[i][4] + dp[4];
                    t4 = max(t4, a[i][4] + max3(dp[2],dp[3],dp[1]));
                }else{
                    ll k = max4(dp[1],dp[2],dp[3],dp[4]);
                    t1 = a[i][1] + k;
                    t2 = a[i][2] + k;
                    t3 = a[i][3] + k;
                    t4 = a[i][4] + k;
                }
                dp[1] = t1, dp[2] = t2, dp[3] = t3, dp[4] = t4;
            }
        }
        printf("Case #%d: %lld\n",t,max4(dp[1], dp[2], dp[3], dp[4]));
    }


    return 0;
}
