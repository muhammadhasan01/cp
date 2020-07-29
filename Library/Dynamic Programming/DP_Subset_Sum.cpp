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
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
// Given a set of non-negative integers
// and a value sum, determine if there is a subset of the given set
// with sum equal to given sum.

// Optimal Substructure :
// let i be the number of elements and j be the value
// dp[i][j] = true (if j == 0)
// dp[i][j] = false (if i == 0)
// dp[i][j] = dp[i-1][j] (if sets[i] > j)
// dp[i][j] = (dp[i-1][j] || dp[i-1][j - sets[i]]) (if sets[i] <= j)

int sets[] = {3,34,4,12,5,2};
int k = sizearr(sets);
int value = 9;

bool recursive_is_subset(int i, int v){
    if(i == 0 && v != 0){
        return false;
    }
    if(v == 0 || sets[i-1] == v){
        return true;
    }
    bool x = recursive_is_subset(i-1,v);
    if(sets[i-1] < v){
        bool y = recursive_is_subset(i-1,v-sets[i-1]);
        return (x || y);
    }
    return x;
}

bool iterative_is_subset(int n, int v){
    // The value of subset[i][j] will be true if there is a
    // subset of set[0..i-1] with sum equal to j

    bool dp[n+3][v+3];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=v;j++){
            if(j == 0){
                dp[i][j] = true;
            }
            else if(i == 0){
                dp[i][j] = false;
            }else{
                if(sets[i-1] <= j){
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-sets[i-1]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return dp[n][v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cout << recursive_is_subset(k,value) << "\n";
    cout << iterative_is_subset(k,value) << "\n";

    return 0;
}
