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
int n,k,a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    forn(i,1,n)cin >> a[i];
    sort(a+1,a+1+n);
    //forn(i,1,n)cerr << a[i] << " ";
    int ans = 0;
    for(int i=1;i<=n;i++){
        int it = upper_bound(a+1+i,a+1+n,a[i]+k) - a;
        it--;
        if(it > i && a[it] != a[i])ans++;
        //cerr << i << " => " << it << " => " << ans << "\n";
    }
    cout << n - ans << "\n";




    return 0;
}
