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
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

struct st{
    int l,r;
    ll x;
};

const int M = 53;
int n,m;
ll h;
st re[M];

bool cmpr(st a, st b){
    if(a.l == b.l){
        return a.r < b.r;
    }
    return a.l < b.l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h >> m;
    forn(i,1,m)cin >> re[i].l >> re[i].r >> re[i].x;

    sort(re+1,re+1+m,cmpr);

    ll a[n+3];
    forn(i,1,n)a[i] = h*h;
    forn(i,1,m){
        forn(j,re[i].l,re[i].r){
            a[j] =min(a[j], re[i].x * re[i].x);
        }
    }

    ll ans = 0;
    forn(i,1,n)ans += a[i];
    cout << ans << "\n";



    return 0;
}
