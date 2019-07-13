#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

// to find (x,y) pair such that ax + by = gcd(a,b)
ll egcd(ll a, ll b, ll &x, ll &y){
    if(a == 0){
        x = 0; y = 1; return b;
    }
    ll x1, y1;
    ll d = egcd(b%a, a,x1,y1);
    x = y1-(b/a)*x1;
    y = x1;
    return d;
    // d = gcd(a,b)
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a,b,x,y;
    a = 4, b = 6;
    ll gcd = egcd(a,b,x,y);
    cout << x << " " << y << " " << gcd << "\n";
    // x = -1, y = 1, gcd = 2
    return 0;
}
