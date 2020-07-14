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

// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// https://practice.geeksforgeeks.org/problems/cutted-segments/0

// Given a rod of length n inches and an array of prices
// that contains prices of all pieces of size smaller than n.
// Determine the maximum value obtainable by cutting up the rod and selling the pieces

const int NMAX = 100;
int tc,n;
int a[NMAX+3];

// Optimal Substructure :
// let i be the length of the red
// dp[i] = price[i-1] (if i == 1)
// dp[i] = max(dp[i], dp[j-i]+dp[i]) (iterate from j = 1 to j = i/2)

int cutting_rod(){
    int dp[n+3];
    for(int i=1;i<=n;i++){
        if(i == 1){
            dp[i] = a[i-1];
        }else{
            dp[i] = a[i-1];
            for(int j=1;j<=i/2;j++){
                dp[i] = max(dp[i],dp[j] + dp[i-j]);
            }
        }
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << cutting_rod() << "\n";
    }

    return 0;
}
