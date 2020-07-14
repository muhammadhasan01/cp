#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define debug1(i) printf("debug => %d\n",i);
#define debug2(i,j) printf("debug => %d - %d\n",i,j);
#define debug3(i,j,k) printf("debug => %d - %d - %d\n",i,j,k);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// Given weights and values of n items
// put these items in a knapsack of capacity W
// to get the maximum total value in the knapsack

// Optimal Substructure :
// let i be the number of weights and j be the capacity
// dp[i][j] = 0 (if i == 0 or j == 0)
// dp[i][j] = dp[i-1][j] (don't include the i-th element)
// dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j - w[i]]) (include the i-th element if j >= w[i])

const int NMAX = 100*1000;
const int WMAX = 1000;
int value[] = {60,100,120};
int weight[] = {10,20,30};
int N = sizearr(value);
int W = 50;
int dp[NMAX+3][WMAX+3];

int recursive_dp(int i, int w){
    if(i == 0 || w == 0){
        return 0;
    }else{
        int k = recursive_dp(i-1,w);
        if(weight[i-1] <= w){
            k = max(k, value[i-1]+recursive_dp(i-1,w-weight[i-1]));
        }
        return k;
    }
}

int iterative_dp(){

    for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i-1][j];
                if(weight[i-1] <= j){
                    dp[i][j] = max(dp[i][j], value[i-1] + dp[i-1][j-weight[i-1]]);
                }
            }
        }
    }
    return dp[N][W];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << recursive_dp(3, W) << "\n";
    cout << iterative_dp() << "\n";


    return 0;
}
