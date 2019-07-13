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


int m = 2;
typedef vector<vector<ll>> matrix;

matrix mul(matrix a, matrix b){
    vector<ll> g(m,0); // vector g has m-zero values
    matrix c(m,g);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                c[i][j] += (a[i][k]%MOD) * (b[k][j]%MOD)%MOD;
            }
        }
    }
    return c;
}

matrix mpow(matrix a, int p){
    //cerr << " * " << p << "\n";
    if(p == 1){
        return a;
    }
    if(p%2 == 1){
        return mul(a, mpow(a,p-1));
    }
    matrix x = mpow(a,p/2);
    return mul(x,x);
}

ll fibo(int k, matrix t){
    int f0 = 1;
    int f1 = 1;

    if(k == 0)return f0;
    if(k == 1)return f1;

    matrix g = mpow(t,k);

    return (g[0][0]*f0+g[0][1]*f1)%MOD;

    // (Fn  ) = (0  1)^n (F0)
    // (Fn+1) = (1  1)   (F1)
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    matrix pengkali = {{0,1},{1,1}};
    cout << fibo(5,pengkali) << "\n";


    return 0;
}
