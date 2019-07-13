#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

typedef vector<vector<ll>> matrix;
const int sz = 2;
int tc;
ll n,m;

matrix mul(matrix a, matrix b){
    vector<ll> g(sz,0);
    matrix c(sz,g);
    forn(i,0,sz-1){
        forn(j,0,sz-1){
            forn(k,0,sz-1){
                c[i][j] += (a[i][k]%MOD)*(b[k][j]%MOD)%MOD;
            }
        }
    }
    return c;
}

matrix mpow(matrix a, int p){
    if(p == 1)return a;
    if(p%2 == 1)return mul(a,mpow(a,p-1));
    matrix x = mpow(a,p/2);
    return mul(x,x);
}

ll fib(int k, matrix t){
    ll f0 = 1, f1 = 1;
    if(k == 0)return f0;
    if(k == 1)return f1;
    matrix g = mpow(t,k);
    return (g[0][0]*f0%MOD+g[0][1]*f1%MOD)%MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    matrix kali = {{0,1},{1,1}};

    cin >> tc;
    while(tc--){
        cin >> n >> m;
        ll x1 = fib(m+1,kali), y1 = fib(n,kali);
        cout << ((x1-y1)%MOD+MOD)%MOD << "\n";
    }


    return 0;
}
