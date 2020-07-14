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

// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/
// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
// Optimal Substructure :
// dp[i] = sum of elements ending with a[i]
// dp[1] = a[1]
// dp[i] = max(dp[i],a[i] + max(dp[j])) where (j < i && a[j] < a[i])

int tc, n, a[1000*1000+3];

ll solve(){
    ll dp[n+3];
    for(int i=0;i<n;i++){
        dp[i] = a[i];
        for(int j=0;j<i;j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i],dp[j]+a[i]);
            }
        }
    }
    return *max_element(dp,dp+n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        form(i,n){
            cin >> a[i];
        }
        cout << solve() << "\n";
    }


    return 0;
}
