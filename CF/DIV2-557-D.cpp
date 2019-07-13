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

const int N = 2e5+5;
int n,m;
pii x[N];

pii f(pii a, int k){
    int ra = a.ff + k;
    int rb = a.ss + k;
    if(ra > n)ra -=n; if(rb > n)rb -= n;
    return {min(ra,rb), max(ra,rb)};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    set<pii> s;
    forn(i,1,m){
        cin >> x[i].ff >> x[i].ss;
        if(x[i].ff > x[i].ss)swap(x[i].ff,x[i].ss);
        s.insert({x[i].ff,x[i].ss});
    }

    forn(k,1,n-1){
        if(n%k)continue;
        bool ok = true;
        forn(i,1,m){
            pii a = {x[i].ff,x[i].ss};
            if(s.find(f(a,k)) == s.end()){
                ok = false; break;
            }
        }
        if(ok){cout << "Yes\n"; ex;}
    }

    cout << "No\n";




    return 0;
}
