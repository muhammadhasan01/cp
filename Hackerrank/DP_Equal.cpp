#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define formn(i,n) for(int i=0;i<=(int)n;i++)
#define debug1(i) printf("debug => %ld\n",i);
#define debug2(i,j) printf("debug => %ld - %ld\n",i,j);
#define debug3(i,j,k) printf("debug => %ld - %ld - %ld\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.hackerrank.com/challenges/equal/problem

/*
Solution :
Christy has to equalize the number of chocolates for all the coworkers.
The only action she can make at every operation is to increase the count of
every others' chocolate by 1,2 or 5 except one of them. This is equivalent to saying,
christy can take away the chocolates of one coworker by 1, 2 or 5 while keeping others'
chocolate untouched
*/

int tc, n, a[10003];
int c[3] = {1,2,5};
int mnm, mxm;

int solve(){
    int ans = inf;
    for(int x = mnm; x>=mnm-4;x--){
        int dp[mxm+1];
        dp[x] = 0;
        for(int i=x+1;i<=mxm;i++){
            dp[i] = inf;
            for(int j=0;j<3;j++){
                if(c[j]+x <= i && dp[i] > dp[i-c[j]]+1){
                    dp[i] = dp[i-c[j]]+1;
                }
            }
        }
        int tmp = 0;
        for(int i=0;i<n;i++){
            tmp += dp[a[i]];
        }
        ans = min(ans,tmp);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        mnm = inf, mxm = -inf;
        form(i,n){
            cin >> a[i]; a[i]+=8;
            mnm = min(mnm,a[i]);
            mxm = max(mxm,a[i]);
        }
        cout << solve() << "\n";
    }


    return 0;
}
