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

// https://www.geeksforgeeks.org/shortest-common-supersequence/
// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
// https://www.techiedelight.com/shortest-common-supersequence-finding-scs/

// Given two strings str1 and str2
// find the length of the smallest string which has both, str1 and str2 as its sub-sequences.

// find length of LCS and return str1.size() + str2.size() - lcs

int tc;
int dp[1003][1003];
string a, b;
int n,m;

int SCS(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                if(a[i-1] == b[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    int ans = n+m-dp[n][m];
    return ans;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> a >> b;
        n = LEN(a), m = LEN(b);
        cout << SCS() << "\n";
    }

    return 0;
}
