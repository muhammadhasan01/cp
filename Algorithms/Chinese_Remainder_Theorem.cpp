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
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/chinese-remainder-theorem-set-2-implementation/

// make inverse_modulo using extended euclid algorithm
ll egcd(ll a, ll b, ll &x, ll &y){
    if(a == 0){
        x = 0, y = 1;
        return b;
    }
    ll x1,y1;
    ll d = egcd(b%a,a,x1,y1);
    x = y1-(b/a)*x1;
    y = x1;
    return d;
}

ll inv(ll a, ll b){
    ll x,y;
    egcd(a,b,x,y);
    return (x%b+b)%b;
}

ll findMinX(ll num[], ll rem[], int k){
    ll prod = 1;
    for(int i=0;i<k;i++){
        prod *= num[i];
    }
    ll res = 0;
    for(int i=0;i<k;i++){
        ll pp = prod/num[i];
        res += (rem[i]*inv(pp,num[i])*pp)%prod;
    }
    return res%prod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll num[] = {3,4,5};
    ll rem[] = {2,3,1};
    // all of elements in num has to be coprime
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << findMinX(num, rem, k) << "\n";

    return 0;
}
