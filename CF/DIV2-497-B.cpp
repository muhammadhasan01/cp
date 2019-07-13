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
int n;
pll x[N];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        cin >> x[i].ff >> x[i].ss;
    }
    ll first = max(x[1].ff, x[1].ss);
    forn(i,2,n){
        ll a = max(x[i].ff, x[i].ss), b = min(x[i].ff, x[i].ss);
        if(first >= a){
            first = a;
        }else if(first >= b){
            first = b;
        }else{
            puts("NO"); ex;
        }
    }

    puts("YES");







    return 0;
}
