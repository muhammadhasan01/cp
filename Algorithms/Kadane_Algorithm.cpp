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
#define debug1(i) printf("debug => %ld\n",i);
#define debug2(i,j) printf("debug => %ld - %ld\n",i,j);
#define debug3(i,j,k) printf("debug => %ld - %ld - %ld\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

int tc,n,a[1003];

int solve(){
    int max_far = -inf, max_end = 0;
    form(i,n){
        max_end += a[i];
        if(max_far < max_end){
            max_far = max_end;
        }
        if(max_end < 0){
            max_end = 0;
        }
    }
    return max_far;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        form(i,n)cin >> a[i];
        cout << solve() << "\n";
    }


    return 0;
}
