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

const int N = 1e3+5;
int n,m;
int c[N], a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,n)cin >> c[i];
    forn(i,1,m)cin >> a[i];

    int ans = 1, res = 0;
    forn(i,1,n){
        //cerr << c[i] << " " << a[ans] << "\n";
        if(c[i] <= a[ans]){
            ans++;
        }

        if(ans > m)break;
    }

    cout << ans-1 << "\n";





    return 0;
}
