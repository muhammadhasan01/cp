#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

const int M = 1e9+7;
const int m = 1e9+6;

matrix cp = {{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1},{1,-1,0,-2,3}};
matrix f = {{0,1,0},{0,0,1},{1,1,1}};
matrix fn;

matrix mul(matrix a, matrix b, int sz){
    vector<ll> g(sz,0);
    matrix ret(sz,g);
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            for(int k=0;k<sz;k++){
                ret[i][j] += (a[i][k] % m) * (b[k][j] % m);
                ret[i][j] %= m;
            }
        }
    }
    return ret;
}

matrix fastpow(matrix a, ll k, int sz){
    if(k == 1)return a;
    if(k&1)return mul(a, fastpow(a,k-1,sz),sz);
    matrix x = fastpow(a,k/2,sz);
    return mul(x,x,sz);
}

ll fast(ll x, ll y){
    ll ret = 1;
    while(y > 0){
        if(y&1){
            ret = (ret * x)%M;
        }
        y >>= 1;
        x = (x*x)%M;
    }
    return (ret%M + M)%M;
}

ll c(ll n){
    ll k1 = 0, k2 = 0, k3 = 0, k4 = 2, k5 = 6;
    if(n <= 3)return k1;
    if(n == 4)return k4;
    if(n == 5)return k5;

    matrix res = fastpow(cp,n-1,5);
    return (k4 * res[0][3])%m + (k5 * res[0][4])%m;
}

ll f1(ll n){
    ll k1 = 1,k2 = 0,k3 = 0;
    if(n == 1)return k1;
    if(n == 2)return k2;
    if(n == 3)return k3;

    return (k1 * fn[0][0])%m + (k2 * fn[0][1])%m + (k3 * fn[0][2])%m;
}

ll f2(ll n){
    ll k1 = 0,k2 = 1,k3 = 0;
    if(n == 1)return k1;
    if(n == 2)return k2;
    if(n == 3)return k3;

    return (k1 * fn[0][0])%m + (k2 * fn[0][1])%m + (k3 * fn[0][2])%m;
}

ll f3(ll n){
    ll k1 = 0,k2 = 0,k3 = 1;
    if(n == 1)return k1;
    if(n == 2)return k2;
    if(n == 3)return k3;

    return (k1 * fn[0][0])%m + (k2 * fn[0][1])%m + (k3 * fn[0][2])%m;
}

ll n, C, F1, F2, F3;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /* -- Sketches --
    c[n] = 3c[n-1] - 2c[n-2] - c[n-4] + c[n-5] (jun's idea :v)
    c[0] = 0, c[1] = 0, c[2] = 0, c[3] = 0, c[4] = 2, c[5] = 6

    (0 1 0 0 0)(c[1])     (c[2])
    (0 0 1 0 0)(c[2])     (c[3])
    (0 0 0 1 0)(c[3])  =  (c[4])
    (0 0 0 0 1)(c[4])     (c[5])
    (1 -1 0 -2 3)(c[5])   (c[6])

    fi[n] = fi[n-1] + fi[n-2] + fi[n-3]
    [depends on the f]
    (0 1 0) (f[1])    (f[2])
    (0 0 1) (f[2]) =  (f[3])
    (1 1 1) (f[3])    (f[4])
    */

    cin >> n >> F1 >> F2 >> F3;
    if(n>1)fn = fastpow(f,n-1,3);
    ll ck = (c(n)%m + m)%m;
    ll f1k = (f1(n)%m + m)%m;
    ll f2k = (f2(n)%m + m)%m;
    ll f3k = (f3(n)%m + m)%m;

    ll ans = 1;
    ans = (ans * fast(C,ck))%M;
    ans = (ans * fast(F1,f1k))%M;
    ans = (ans * fast(F2,f2k))%M;
    ans = (ans * fast(F3,f3k))%M;

    cout << ans << "\n";



    return 0;
}
