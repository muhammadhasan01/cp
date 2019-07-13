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

// https://www.geeksforgeeks.org/partition-problem-dp-18/
// https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

// Partition problem is to determine
// whether a given set can be partitioned into two subsets
// such that the sum of elements in both subsets is same.

// Optimal Substructure :
// let i be the number of elements and j be the value
// dp[i][j] = false (if i == 0)
// dp[i][j] = true (if j == 0)
// dp[i][j] = dp[i-1][j] (if a[i-1] > j )
// dp[i][j] = (dp[i-1][j] || dp[i-1][j - a[i-1]]) (If a[i-1] <= j)

const int NMAX = 100;
int tc,n;
int a[NMAX+3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        int sum = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum & 1){
            cout << "NO\n";
        }else{
            int v = sum/2;
            bool dp[n+3][v+3];
            for(int i=0;i<=n;i++){
                for(int j=0;j<=v;j++){
                    if(i == 0){
                        dp[i][j] = false;
                    }else if(j == 0){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i-1][j];
                        if(j >= a[i-1]){
                            dp[i][j] = (dp[i-1][j] || dp[i-1][j - a[i-1]]);
                        }
                    }
                }
            }
            if(dp[n][v]){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }

    return 0;
}
