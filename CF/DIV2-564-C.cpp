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
int n, a[N], b[N], p[N], ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        cin >> a[i];
        p[a[i]] = 0;
    }

    forn(i,1,n){
        cin >> b[i];
        p[b[i]] = i;
    }

    if(p[1]){
        int i,j;
        for(i=2; p[i] == p[1]+i-1; ++i);
        if(p[i-1] == n){
            for(j = i; j<=n && p[j]<=j-i ; ++j);
            if(j > n){
                cout << n - i + 1 << '\n';
                ex;
            }
        }
    }

    forn(i,1,n)ans = max(ans, p[i] - i + 1 + n);

    cout << ans << "\n";




    return 0;
}
