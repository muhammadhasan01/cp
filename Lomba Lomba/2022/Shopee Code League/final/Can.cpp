// Author: Micchon
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>
#define matrix vector<vector<int>>

const int MOD = 1000000007;
//const int MOD = 998244353;
int n,n2;
int dx[] = {2,2,2,0,0,-2,-2,-2};
int dy[] = {2,0,-2,2,-2,2,0,-2};

matrix kali(matrix &a, matrix &b)
{
    assert(a[0].size() == b.size());
    matrix ret(a.size(),vi(b[0].size(),0));
    forn(i,a.size()) forn(j,b.size()) forn(k,b[0].size()){
        ret[i][k] += (a[i][j] % MOD) * (b[j][k] % MOD);
        ret[i][k] %= MOD;
    }
    return ret;
}

matrix init()
{
    if(n == 1){
        matrix ret(1,vi(1,1));
        return ret;
    }
    matrix ret(n2,vi(n2,0));
    forn(i,n) forn(j,n){
        forn(k,8){
            int x = i + dx[k] , y = j + dy[k];
            if(x < 0 || y < 0 || x >= n || y >= n) continue;
            ret[x*n+y][i*n+j] = 1;
        }
        if(i == 1 || j == 1 || i == n-2 || j == n-2) ret[i*n+j][i*n+j] = 1;
    }
    return ret;
}

matrix satu()
{
    matrix ret(n2,vi(n2,0));
    forn(i,n2) ret[i][i] = 1;
    return ret;
}

matrix fpow(matrix &a, int e)
{
    if(!e) return satu();
    matrix b = fpow(a,e/2);
    b = kali(b,b);
    if(e%2) b = kali(b,a);
    return b;
}

matrix pos_awal(int a,int b)
{
    matrix ret(n2,vi(1,0));
    ret[a*n+b][0] = 1;
    return ret;
}

void printm(matrix &a)
{
    forn(i,a.size()){
        forn(j,a[0].size()){
            cout << a[i][j] << ' ';
        }cout << '\n';
    }
}

int32_t main()
{
    //ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n; n2 = n * n;
    matrix p = init();

    int a,b; cin >> a >> b;
    matrix awal = pos_awal(a,b);
    int x,y,k;
	cin >> x >> y >> k;
	matrix pengali = fpow(p,k);
	matrix ans = kali(pengali , awal);
	cout << ans[x*n+y][0] << '\n';

    return 0;
}
