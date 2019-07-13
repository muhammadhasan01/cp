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

const int N = 1e5+5;
int n,m;
ll b[N], g[N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,n)cin >> b[i];
    forn(i,1,m)cin >> g[i];

    sort(b+1,b+1+n);
    sort(g+1,g+1+m);

    if(g[1] < b[n]){
        cout << "-1\n";
    }else{
        ll ans = 0;
        if(n == 1){
            if(g[1] != b[1]){
                cout << "-1\n"; return 0;
            }
            forn(i,1,m)ans += g[i];
        }else if(m == 1){
            if(g[1] != b[n]){
                cout << "-1\n"; return 0;
            }
            forn(i,1,n)ans += b[i];
        }else{
            forn(i,2,m)ans += g[i];
            if(g[1] == b[n]){
                ans += g[1];
                forn(i,1,n-1)ans += b[i] * m;
            }else{
                ans += b[n];
                ans += b[n-1] * (m - 1) + g[1];
                forn(i,1,n-2)ans += b[i] * m;
            }
        }
        cout << ans << '\n';
    }



    return 0;
}
