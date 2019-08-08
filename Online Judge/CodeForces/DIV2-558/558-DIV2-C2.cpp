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

const int N = 1e3+5;
int n;
int x[N],y[N];
map<pii,set<ll>> m;
ll tot, res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n)cin >> x[i] >> y[i];
    forn(i,1,n-1){
        forn(j,i+1,n){
            int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
            int a = y1-y2, b = x1-x2;
            int d = __gcd(a,b); a /= d, b /= d;
            if(a < 0 || (a == 0 && b < 0)){a = -a, b = -b;}
            pii sl = {a,b};
            ll c = ((ll)a * x1 - (ll)b * y1);
            if(!m[sl].count(c)){
                tot++;
                m[sl].insert(c);
                res += tot - len(m[sl]);
            }
        }
    }
    cout << res << "\n";


    return 0;
}
