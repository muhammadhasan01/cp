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

int tc;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<ll> a(n);
        forn(i,0,n-1)cin >> a[i];
        sort(all(a));
        ll ans = a[0] * a[n-1];
        vector<ll> b;
        for(ll i=2;i*i<=ans;i++){
            if(ans%i == 0){
                b.pb(i);
                if(i*i != ans){
                    b.pb(ans/i);
                }
            }
        }
        //cout << len(b) << " and " << len(a) << "\n";
        if(len(b) != len(a)){
            //cout << "huh?\n";
            cout << -1 << "\n";
        }else{
            sort(all(b));
            if(a != b){
                cout << -1 << "\n";
            }else{
                cout << ans << "\n";
            }
        }
    }


    return 0;
}
