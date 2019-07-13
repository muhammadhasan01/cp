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

const int N = 3e5+5;
int n;
pii a[N];
int x[N], y[N];

bool cstm(pii x, pii y){
    if(x.ff == y.ff){
        return x.ss < y.ss;
    }
    return x.ff < y.ff;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        cin >> a[i].ff;
        a[i].ss = i;
        x[i] = inf;
        y[i] = -1;
    }

    sort(a+1,a+1+n,cstm);

    x[n] = a[n].ss;
    y[n] = a[n].ss;
    nrof(i,n-1,1){
        x[i] = min(x[i+1], a[i].ss);
        y[i] = max(y[i+1], a[i].ss);
    }

    int ans = inf;
    forn(i,1,n-1){
        int p = a[i].ff, ix = a[i].ss;
        ans = min(ans, p/abs(ix - x[i+1]));
        ans = min(ans, p/abs(ix - y[i+1]));
    }

    cout << ans << "\n";



    return 0;
}
