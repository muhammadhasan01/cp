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
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 2e5+5;
int n;
ll a[N], t, ans = 0, minim = inf;

void search(ll x, ll &cnt, ll &sum){
    forn(i,1,n){
        if(x >= a[i]){
            x -= a[i];
            cnt++;
            sum += a[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    forn(i,1,n)cin>>a[i],minim = min(minim,a[i]);
    while(t >= minim){
        ll cnt = 0, sum = 0;
        search(t,cnt,sum);
        ans += (t/sum)*cnt;
        t %= sum;
    }

    cout << ans << "\n";

    return 0;
}
