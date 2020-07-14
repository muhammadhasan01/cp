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

// https://www.geeksforgeeks.org/min-cost-path-dp-6/
// https://practice.geeksforgeeks.org/problems/path-in-matrix/0

// Given a cost matrix cost[][] and a position (m, n) in cost[][]
// write a function that returns cost of minimum cost path to reach (m, n) from (0, 0)

const int NMAX = 20;
int tc,n;
int a[NMAX+3][NMAX+3];

int min_cost_path(){
    int dp[n+3][n+3];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(i == 1){
                dp[i][j] = a[i][j]+dp[i][j-1];
            }else if(j == 1){
                dp[i][j] = a[i][j]+dp[i-1][j];
            }else{
                dp[i][j] = a[i][j]+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> a[i][j];
            }
        }
        cout << min_cost_path() << "\n";
    }

    return 0;
}
