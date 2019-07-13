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
#define debug1(i) printf("debug => %d\n",i);
#define debug2(i,j) printf("debug => %d - %d\n",i,j);
#define debug3(i,j,k) printf("debug => %d - %d - %d\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

// Given a set of integers
// the task is to divide it into two sets S1 and S2
// such that the absolute difference between their sums is minimum.

// Optimal Substructure :
// Use dp[i][j] where i is the number of elements and j is the value
// dp[i][j] = true (if there is a subset which has the sum j from 0 to i-1)
// dp[i][j] = false (otherwise)
// iterate from 0 to half of the sum and find the nearest to the half of the sum

const int NMAX = 100;
int tc, n;
int a[NMAX+3];

int minimum_partition(){
    int sum = accumulate(a,a+n,0);
    bool dp[n+3][sum+3];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j == 0){
                dp[i][j] = true;
            }else if(i == 0){
                dp[i][j] = false;
            }else{
                dp[i][j] = dp[i-1][j];
                if(a[i-1] <= j){
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-a[i-1]]);
                }
            }
        }
    }
    int ans = inf;
    for(int i=0;i<=sum/2;i++){
        if(dp[n][i]){
            ans = min(ans,sum - 2*i);
        }
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
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << minimum_partition() << "\n";
    }

    return 0;
}
