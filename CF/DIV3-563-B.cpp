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


int tc, n;
ll a[105];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n;
        int a = 0,b = 0,c = 0;
        forn(i,1,n){
            int x; cin >>x;
            if(x%3 == 0){
                a++;
            }else if(x%3 == 1){
                b++;
            }else if(x%3 == 2){
                c++;
            }
        }
        int ans = a + min(b,c);
        if(b > c){
            b -= c;
            ans += b/3;
        }else if(b < c){
            c -= b;
            ans += c/3;
        }
        cout << ans << "\n";
    }


    return 0;
}
