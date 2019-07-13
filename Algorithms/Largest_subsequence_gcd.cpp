#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/largest-subsequence-gcd-greater-1/

const int N = 15*1000*1000;
int prime[N+5], countdiv[N+5], n, a[300005];

int solve(){

    prime[1] = 1;
    for(int i=2;i*i<=N+3;i++){
        if(!prime[i]){
            for(int j=i;j<=N+3;j+=i)
                prime[j] = i;
        }
    }

    int fpb = a[1];
    forn(i,n)fpb = __gcd(fpb,a[i]);
    if(fpb>1)forn(i,n)a[i]/=fpb;
    int ans = 0;
    forn(i,n){
        int x = a[i];
        while(x > 1){
            int div = prime[x];
            ++countdiv[div];
            ans = max(ans,countdiv[div]);
            while(x%div == 0)
                x/=div;
        }
    }
    if(ans == 0)return -1;
    return n-ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,n)cin>>a[i];
    cout << solve() << "\n";
    return 0;
}
