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

// https://www.geeksforgeeks.org/edit-distance-dp-5/
// https://www.hackerrank.com/contests/cse-830-homework-3/challenges/edit-distance/problem
// Given two strings str1 and str2 and below operations that can performed on str1.
// Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’
// (the edit operations are add, remove, and replace)

// Optimal Substructure :
// let i be the index for the first string and j for the second string
// dp[i][j] = j (if j == 0)
// dp[i][j] = i (if i == 0)
// dp[i][j] = dp[i-1][j-1] (if str[i-1] == str[j-1])
// dp[i][j] = 1 + minimum(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) (if str[i-1] != str[j-1])
// (remove => dp[i-1][j], insert => dp[i][j-1], replace => dp[i-1][j-1])

string str1 = "sxyagf";
string str2 = "sabcf";
int n = (int)str1.size();
int m = (int)str2.size();

int minimum(int x, int y, int z){
    return min(min(x,y),z);
}

int recursive_edit_distance(int i, int j){
    // if the first string is empty then insert all character of second string
    if(i == 0){
        return j;
    }
    // vice versa with the second string
    if(j == 0){
        return i;
    }

    // if the last character is the same, then just skip
    if(str1[i-1] == str2[j-1]){
        return recursive_edit_distance(i-1,j-1);
    }
    // otherwise, consider all three options
    int insert = recursive_edit_distance(i,j-1);
    int remove = recursive_edit_distance(i-1,j);
    int replace = recursive_edit_distance(i-1,j-1);
    return 1 + minimum(insert,remove,replace);
}

int iterative_edit_distance(){
    int dp[n+3][m+3];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0){
                dp[i][j] = j;
            }else if(j == 0){
                dp[i][j] = i;
            }else{
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + minimum(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
                }
            }
        }
    }
    return dp[n][m];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cout << recursive_edit_distance(n,m) << "\n";
    cout << iterative_edit_distance() << "\n";
    cout << lcs_solution() << "\n";

    return 0;
}
