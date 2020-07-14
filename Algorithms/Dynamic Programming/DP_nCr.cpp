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

// https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
// https://practice.geeksforgeeks.org/problems/ncr/0

// Optimal Substructure :
// c(n,k) = c(n-1,k-1)+c(n-1,k)
// c(n,0) = c(n,n) = 1

int tc;
int n,r;

int nCr(){
    int c[r+1];
    MEM(c,0);
    c[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=min(i,r);j>0;j--){
            c[j] = (c[j]+c[j-1])%MOD;
        }
    }
    return c[r]%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n >> r;
        cout << nCr() << "\n";
    }

    return 0;
}
