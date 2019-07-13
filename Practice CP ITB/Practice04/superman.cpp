#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 200*1000;
ll n,m,temp, best = -1, idx;
ll a[N+2], b[N+2], h[N+2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        if(i>=1){h[i] = h[i-1]+a[i]-b[i-1];}
    }
    /*cout << "\n";
    for(int i=0;i<n;i++){
        cout << i << " => " << h[i] << "\n";
    }cout << "\n";*/
    if(n==1){cout<<b[0]-a[0]+m<<"\n"; return 0;}
    else{
        for(int i=0;i<n-1;i++){
            ll *p = upper_bound(h,h+n,h[i]+m)-1;
            if(*p == h[i]+m){p--;}
            //cout << i << " => " << p-h << " => ";
            idx  = p-h;
            temp = m-h[idx]+h[i];
            //cout << temp << " => " << temp+b[idx]-a[i] << "\n";
            best = max(best, temp+b[idx]-a[i]);
        }
    }
    best = max(best,b[n-1]-a[n-1]+m);
    cout << best << "\n";
    return 0;
}
