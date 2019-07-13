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
int a[N];

int l = 1, r = 1;
ll ans = 0;

bool check(ll x){
    return (x%4 == 0) ? true : false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n)cin >> a[i];
    ll x = 1;
    while(l <= n && r <= n){
        if(a[r]%4 == 0){
            x *= 4;
        }else if(a[r]%2 == 0){
            x *= 2;
        }
        while(check(x) && l <= r){
            ans += n-r+1;
            if(a[l]%4 == 0)x/=4;
            else if(a[l]%2 == 0)x/=2;
            l++;
        }
        r++;
    }

    cout << ans << '\n';

    return 0;
}
