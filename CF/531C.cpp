#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define rofn(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,x,y;
ll a[100003];

ll solve(){
    if(x > y){
        return n;
    }
    sort(a+1,a+1+n);
    ll cnt = 0;
    for(int i=1;i<=n;i+=2){
        if(a[i] <= x){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;
    forn(i,1,n)cin >> a[i];
    cout << solve() << "\n";

    return 0;
}
