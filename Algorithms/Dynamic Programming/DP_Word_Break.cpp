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

// https://www.geeksforgeeks.org/word-break-problem-dp-32/

int tc,n,k;
string d[16],s;

// Optimal Substructure :
// dp[i][j] = true/false if it can be breaked from i to j
// dp[i][j] = true/false (for i == j and a.substr(i,1) == d[x])
// dp[i][j] = (dp[i][x] && dp[x][j]) for (i <= x <= j)

int word_break(){
    if(k == 0){
        return true;
    }
    int dp[k+3][k+3];
    for(int j=0;j<=k;j++){
        for(int i=1;i+j<=k;i++){
            dp[i][i+j] = 0;
            for(int x=0;x<n;x++){
                if(s.substr(i-1,j+1) == d[x]){
                    dp[i][i+j] = 1;
                    break;
                }else if(j > 0){
                    for(int x=i;x<=i+j-1;x++){
                        dp[i][i+j] = (dp[i][x] & dp[x+1][i+j]);
                        if(dp[i][i+j] == 1){
                            break;
                        }
                    }
                    if(dp[i][i+j] == 1){
                        break;
                    }
                }
            }
        }
    }
    return dp[1][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        form(i,n){
            cin >> d[i];
        }
        cin >> s;
        k = LEN(s);
        cout << word_break() << "\n";
    }

    return 0;
}
