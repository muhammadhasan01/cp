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

// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

const int LMAX = 1000;
string a,b;
int dp[LMAX+3][LMAX+3];

// Optimal Substructure :
// dp[i][j] = 0 (if i == 0 or j == 0)
// dp[i][j] = 1+dp[i-1][j-1] (if a[i] == b[j])
// dp[i][j] = max(dp[i-1][j],dp[i][j-1])

int rec_lcs(int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i == 0 || j == 0){
        return 0;
    }
    if(a[i-1] == b[j-1]){
        dp[i][j] = 1+rec_lcs(i-1,j-1);
    }else{
        dp[i][j] = max(rec_lcs(i-1,j),rec_lcs(i,j-1));
    }
    return dp[i][j];
}

int iter_lcs(int n, int m){

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

    return dp[n][m];
}

void print_lcs(int n, int m){
    string res = "";
    int i = n, j = m;
    while(i > 0 || j > 0){
        if(a[i-1] == b[j-1]){
            res = a.substr(i-1,1)+res;
            i--;
            j--;
        }else{
            if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    a = "AGGTAB", b = "GXTAYB";
    int n = (int)a.size(), m = (int)b.size();
    MEM(dp,-1);
    cout << rec_lcs(n,m) << "\n";
    cout << iter_lcs(n,m) << "\n";
    print_lcs(n,m);

    return 0;
}
