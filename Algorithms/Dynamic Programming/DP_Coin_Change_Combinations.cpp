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

// https://www.geeksforgeeks.org/coin-change-dp-7/
// https://www.hackerrank.com/challenges/coin-change/problem

// Given a value N, if we want to make change for N cents
// and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins
// how many ways can we make the change?

// Optimal Substructure :
// let i be the number of coins and j be the value
// dp[i][j] = 1 (if j == 0)
// dp[i][j] = 0 (if i == 0)
// dp[i][j] = dp[i-1][j] + dp[i][j - c[i]]

const int NMAX = 50;
const int VMAX = 250;
ll c[NMAX+3];
ll dp[NMAX+3][VMAX+3];
int v,n;

ll iterative_dp(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=v;j++){
            if(j == 0){
                // if value is 0, then there is only 1 solution
                // (include no coins)
                dp[i][j] = 1;
            }else{
                if(i == 0){
                    // if there is no coin, then there is no solution
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 0;
                    if(c[i-1] <= j){
                        // include coin i
                        dp[i][j] += dp[i][j-c[i-1]];
                    }
                    // exclude coin i
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
    }
    return dp[n][v];
}

ll compressed(){
    ll table[v+1];
    MEM(table,0);
    table[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=c[i];j<=v;j++){
            table[j] += table[j-c[i]];
        }
    }
    return table[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> n;
    for(int i=0;i<n;i++){
        cin >> c[i];
    }

    cout << iterative_dp() << "\n";

    return 0;
}
