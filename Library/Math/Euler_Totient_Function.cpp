#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define debug1(i) printf("debug %d\n",i);
#define debug2(i,j) printf("debug %d - %d\n",i,j);
#define debug3(i,j,k) printf("debug %d - %d - %d\n",i,j,k);
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

// https://www.geeksforgeeks.org/eulers-totient-function/

int phi(int n){
    int result = n; // initialize result as n

    // consider all prime factors of n and substract their
    // multiples from result
    for(int p=2;p*p<=n;p++){

        // check if p is a prime factor
        if(n%p == 0){

            // if yes, then update n and result
            while(n%p == 0){
                n/=p;
            }
            result -= result/p;
        }
    }

    // if n has a prime factor greater than sqrt(n)
    // (there can be at-most one such prime factor)
    if(n > 1){
        result -= result/n;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 10;
    forn(i,n){
        cout << phi(i) << "\n";
    }

    return 0;
}
