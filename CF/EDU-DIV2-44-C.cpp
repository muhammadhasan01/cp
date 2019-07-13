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

const int N = 1e5+10;
ll n,k,l,m;
ll a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> k >> l;
    m = n*k;
    forn(i,1,m)cin >> a[i];
    sort(a+1,a+1+m);

    //forn(i,1,m)cerr << a[i] << " ";cerr<<'\n';

    ll ans = 0;
    if(a[n] - a[1] > l){cout << ans << "\n"; ex;}

    int pos = m;
    for(int i=m;i>=2;i--){
        if(a[i] - a[1] <= l){
            pos = i; break;
        }
    }

    //cerr << pos << "\n";

    int i = 1;
    int cnt = 1;
    int av = pos - n;
    while(i <= pos){
        ans += a[i];
        while(i <= pos && cnt < k && av > 0){
            i++;
            cnt++;
            av--;
        }
        i++;
        cnt = 1;
    }


    cout << ans << "\n";




    return 0;
}
