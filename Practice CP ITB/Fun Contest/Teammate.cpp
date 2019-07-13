#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<(int)n;i++)
#define forn(n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define csort(x,n) sort(x.begin()+1,x.begin()+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n; int a[n+3];
    forn(n)cin>>a[i];
    sort(a+1,a+1+n);
    int great = inf;
    for(int i=1;i<n;i++){
        great = min(great,a[i+1]-a[i]);
    }
    ll ans = 1;
    for(int i=1;i<=great;i++){
        ans*=i;
    }
    cout << ans << "\n";
    return 0;
}
