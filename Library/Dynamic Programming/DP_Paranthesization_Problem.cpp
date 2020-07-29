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

/*
https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0

Given a boolean expression with following symbols.

Symbols
    'T' ---> true
    'F' ---> false
And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression
so that the value of expression evaluates to true.
*/

int tc,n;
string ss;

ll solve(string s){

    ll dp[n+3][n+3];
    ll pd[n+3][n+3];

    int k;
    for(int j=0;j<=n;j+=2){
        for(int i=1;i+j<=n;i+=2){
            k = i+j;
            if(j == 0){
                if(s[i-1] == 'T'){
                    dp[i][k] = 1;
                    pd[i][k] = 0;
                }else{
                    dp[i][k] = 0;
                    pd[i][k] = 1;
                }
            }else{
                dp[i][k] = 0;
                pd[i][k] = 0;
                for(int x=0;i+x<=k-2;x+=2){
                    int z = i+x;
                    ll tik = dp[i][z]+pd[i][z];
                    ll tkz = dp[z+2][k]+pd[z+2][k];
                    if(s[z] == '&'){
                        dp[i][k] += dp[i][z]*dp[z+2][k];
                        pd[i][k] += (tik)*(tkz)-(dp[i][z]*dp[z+2][k]);
                    }else if(s[z] == '|'){
                        dp[i][k] += (tik)*(tkz)-(pd[i][z]*pd[z+2][k]);
                        pd[i][k] += pd[i][z]*pd[z+2][k];
                    }else if(s[z] == '^'){
                        dp[i][k] += (dp[i][z]*pd[z+2][k])+(pd[i][z]*dp[z+2][k]);
                        pd[i][k] += (dp[i][z]*dp[z+2][k])+(pd[i][z]*pd[z+2][k]);
                    }
                }
            }
        }
    }
    return dp[1][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n >> ss;
        cout << solve(ss) << "\n";
    }

    return 0;
}
