#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define debug(i) printf("debug %d\n",i);
#define debug2(i,j) printf("debug %d - %d\n",i,j);
#define debug3(i,j,k) printf("debug %d - %d - %d\n",i,j,k);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/compute-ncr-p-set-2-lucas-theorem/
// https://brilliant.org/wiki/lucas-theorem/

// returns nCr % p, only called when n,r < p

int nCrModP(int n, int r, int p){
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    int c[r+1];
    MEM(c,0);

    c[0] = 1; // top row of Pascal Triangle

    // one by constructs remaining rows of pascal
    // triangle from top to bottom
    for(int i=1; i<=n; i++){

        // fill entries of current row using previous
        // row values
        for(int j = min(i,r); j > 0; j--){

            // nCj = (n-1)Cj + (n-1)C(j-1)
            c[j] = (c[j]+c[j-1])%p;
        }
    }
    return c[r];
}

// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion
// recursive function.  First we compute last digits of
// n and r in base p, then recur for remaining digits
int nCrModPlucas(int n, int r, int p){
    // base case
    if(r == 0){
        return 1;
    }
    int ni = n%p, ri = r%p; // compute last digit

    // compute result for last digits computed above, and
    // for remaining digits. Multiply the two result and
    // compute the result of multipication in modulo p.
    return (nCrModPlucas(n/p,r/p,p)*
            nCrModP(ni,ri,p))%p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1000, r = 300, p = 13;
    cout << "The value is " << nCrModPlucas(n,r,p) << "\n";

    return 0;
}
