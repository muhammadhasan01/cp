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

ll n;
string a[5];
ll x[5];
char al[30];
char AL[30];

ll pplus(ll ck, ll k){
    if(k >= n){
        return n;
    }else{
        if((n-k)&1){
            return k-1;
        }else{
            return k;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a[1] >> a[2] >> a[3];

    ll sz = len(a[1]);

    if(n >= sz){
        puts("Draw"); ex;
    }

    forn(i,0,25){
        al[i] = char(int('a') + i);
        AL[i] = char(int('A') + i);
        //cerr << al[i] << " " << AL[i] << "\n";
    }

    forn(i,1,3){
        forn(j,0,25){
            ll res = 0, res2 = 0;
            for(auto e:a[i]){
                if(e == al[j])res++;
                if(e == AL[j])res2++;
            }
            x[i] = max(x[i], res + pplus(res,sz - res));
            x[i] = max(x[i], res2 + pplus(res2,sz - res2));
        }
    }

    ll maxx = max(x[1], max(x[2],x[3]));

    cerr << x[1] << " " << x[2] << " " << x[3] << "\n";

    int cnt = 0;
    if(x[1] == maxx)cnt++;
    if(x[2] == maxx)cnt++;
    if(x[3] == maxx)cnt++;

    if(cnt > 1){
        puts("Draw");
    }else{
        if(x[1] == maxx){
            puts("Kuro");
        }else if(x[2] == maxx){
            puts("Shiro");
        }else if(x[3] == maxx){
            puts("Katie");
        }
    }




    return 0;
}
