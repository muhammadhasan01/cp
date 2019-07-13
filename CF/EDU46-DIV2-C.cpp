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
int n;
vector<pll> v;
ll c[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        ll l,r; cin >> l >> r;
        v.pb({l,0});
        v.pb({r+1,1});
    }

    sort(all(v));

    ll last = 0;
    int j = 0;
    forn(i,0,len(v)-1){
        if(v[i].ss){
            c[j] += v[i].ff - last;
            j--;
        }else{
            c[j] += v[i].ff - last;
            j++;
        }
        last = v[i].ff;
    }

    forn(i,1,n){
        cout << c[i] << " ";
    }



    return 0;
}
