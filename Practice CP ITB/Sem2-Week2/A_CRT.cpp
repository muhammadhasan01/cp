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

ll a,n,b,m,g;

ll egcd(ll a, ll b, ll &x, ll &y){
    //cerr << "NANI?\n";
    if(a == 0){x = 0, y = 1; return b;}
    ll x1,y1,d = egcd(b%a,a,x1,y1);
    x = y1-(b/a)*x1;
    y = x1;
    return d;
}

ll inv(ll a,ll b){
    ll x,y;
    egcd(a,b,x,y);
    //cout << "dapat " << x << " dan " << y << "\n";
    return (x%b+b)%b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        //cerr << "omaewa mo shinderu\n";
        cin >> a >> n >> b >> m;
        g = __gcd(n,m);
        if(a%g != b%g){
            cout << "no solution" << endl;
        }else{
            ll t1 = ((b-a)%m+m)%m;
            ll t2 = n%m;
            ll t3 = inv(t2,m);
            ll lcm = n*m/g;
            cout << ((t2*t3*(t1/g)+a)%lcm+lcm)%lcm << " " << lcm << endl;
        }
    }
    return 0;

}
