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
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1e5+3;
const int p = 31;
const int p2 = 53;
const int m = MOD;
vector<ll> p_pow(N), p2_pow(N);
int tc;
int n,k;
string s;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    p_pow[0] = 1, p2_pow[0] = 1;
    forn(i,0,N-1){
        p_pow[i] = (p*p_pow[i-1])%m;
        p2_pow[i] = (p2*p2_pow[i-1])%m;
    }
    while(tc--){
        cin >> n >> k;
        cin >> s;
        vector<ll> h(n+1,0), h2(n+1,0);
        forn(i,0,n-1){
            h[i+1] = (h[i] + (s[i] - 'a' + 1 )* p_pow[i])%m;
            h2[i+1] = (h2[i] + (s[i] - 'a'+ 1)* p2_pow[i])%m;
        }

        set<pll> hs;
        for(int i=0;i<=n-k;i++){
            ll cur_h = (h[i+k] - h[i] + m)%m;
            ll cur_h2 = (h2[i+k] - h2[i] + m)%m;
            cur_h = (cur_h * p_pow[n-i-1])%m;
            cur_h2 = (cur_h2 * p2_pow[n-i-1])%m;
            hs.insert({cur_h,cur_h2});
        }

        cout << LEN(hs) << "\n";
    }




    return 0;
}
