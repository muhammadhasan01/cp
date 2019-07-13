#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,m;
string a,b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> a;
    m = n;
    b = a; reverse(b.begin(),b.end());
    int dp[n+2][m+2];
    for(int i=0; i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //cout << dp[n][m] << "\n";
    int index = dp[n][m];
    string answer = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            answer = a.substr(i-1,1)+answer;
            i--, j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    cout << answer << "\n";
    return 0;
}
