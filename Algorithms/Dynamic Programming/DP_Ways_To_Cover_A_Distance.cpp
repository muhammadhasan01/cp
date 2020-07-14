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


// https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
// https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
// Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps.

// Optimal Substructure :
// dp[1] = 1, dp[2] = 2, dp[3] = 4
// dp[i] = dp[i-1]+dp[i-2]+dp[i-3]

int tc;
int n;

int ways(){
    int dp[n+3];
    for(int i=1;i<=n;i++){
        if(i == 1){
            dp[i] = 1;
        }else if(i == 2){
            dp[i] = 1+dp[i-1];
        }else if(i == 3){
            dp[i] = 1+dp[i-1]+dp[i-2];
        }else{
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        cout << ways() << "\n";
    }

    return 0;
}
