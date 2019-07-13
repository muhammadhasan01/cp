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

int k,n;
pii a[5003];
int b[5003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    forn(i,1,n)cin >> a[i].ff, a[i].ss = i;
    sort(a+1,a+1+n);
    //forn(i,1,n)cout << a[i].ff << " " << a[i].ss << "\n";
    int x = 1, last;
    b[a[x].ss] = x;
    last = a[x].ff;
    int cnt = 1;
    forn(i,2,n){
        if(a[i].ff != last){
            cnt = 1;
            x++;
            if(x > k)x = 1;
            b[a[i].ss] = x;
        }else{
            cnt++;
            x++;
            if(x > k)x = 1;
            b[a[i].ss] = x;
        }
        if(cnt > k){
            cout << "NO\n"; return 0;
        }
        last = a[i].ff;
    }
    cout << "YES\n";
    forn(i,1,n){
        cout << b[i] << " ";
    }

    return 0;
}
