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
int le[N],ri[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> v,right;
    forn(i,1,n){
        int x;
        cin >> x;
        if(le[x] == 0){
            le[x] = i;
            v.pb(x);
        }
        ri[x] = i;
    }

    int k = len(v);
    right.resize(k);
    forn(i,0,k-1){
        right[i] = ri[v[i]];
    }

    sort(all(right));

    ll ans = 0;
    for(auto e:v){
        int m = le[e];
        ll it = right.end() - upper_bound(all(right),m);
        //cerr << m << " => " << it << "\n";
        ans += it;
    }

    cout << ans << "\n";










    return 0;
}
