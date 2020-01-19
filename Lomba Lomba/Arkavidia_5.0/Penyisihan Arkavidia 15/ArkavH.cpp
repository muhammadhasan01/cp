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

int tc,n;
ll x, a[100003];

struct s{
    int prime, count;
    ll rem;
};

s make(int a, int b, ll c){
    s x;
    x.prime = a, x.count = b, x.rem = c;
    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> x >> n;
        ll p = 2, k = 0, cnt = 0;
        vector<s> v;
        while(x != 1){
            if(x%p == 0){
                x/=p;
                cnt++;
            }else{
                v.pb(make(p,cnt,0));
                if(p == 2){
                    p = 3;
                }else{
                    p+=2;
                }
                cnt = 0;
            }
        }
        v.pb(make(p,cnt,0));
        //for(auto e:v){
            //cout << e.prime << " " << e.count << " -> " << e.rem << "\n";
        //}
        forn(i,1,n){
            cin>>a[i];
            for(int j=0;j<LEN(v);j++){
                s e = v[j];
                ll m = e.prime, tmp = 1, q = a[i];
                //cout << q << " - " << m << "\n";
                while(q >= m){
                    m *= m;
                    v[j].rem += tmp;
                    tmp++;
                }
            }
        }
        ll ans = inf;
        for(int i=0;i<LEN(v);i++){
            //cout << v[i].rem << " => " << v[i].count << "\n";
            ans = min(ans, v[i].rem/v[i].count);
        }
        cout << ans << "\n";
    }


    return 0;
}
