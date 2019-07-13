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
matrix kali;
ll pre[103];
ll n,m;

matrix mul(matrix a, matrix b){
    vector<ll> g(m,0);
    matrix c(m,g);
    forn(i,0,m-1){
        forn(j,0,m-1){
            forn(k,0,m-1){
                c[i][j] += (a[i][k]%MOD)*(b[k][j]%MOD)%MOD;
            }
        }
    }
    return c;
}

matrix mpow(matrix a, ll p){
    if(p == 1)return a;
    if(p&1)return mul(a,mpow(a,p-1));
    matrix x = mpow(a,p/2);
    return mul(x,x);
}

ll solve(){
    if(n < m)return 1;
    matrix g = mpow(kali,n);
    ll hasil = 0;
    forn(i,0,m-1){
        hasil += g[0][i]%MOD;
    }
    return (hasil%MOD+MOD)%MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        vector<ll> g(m,0);
        if(i != m-1){
            g[i+1] = 1;
        }else{
            g[0] = 1, g[m-1] = 1;
        }
        kali.pb(g);
    }
    cout << solve() << "\n";

    return 0;
}
