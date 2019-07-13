#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 100*1000;
ll a[NMAX+2];
vector<ll> v[NMAX+2];
ll ans = 0;
int n;

ll dfs(ll s, bitset<NMAX+2> b, ll t){
    if(b[s] == 1){
        ll k = t^a[s];
        //cout << s << " ==> " << t << "^" << a[s] << " => " << k << "\n";
        t = t^a[s];
        ans += t;
        //cout << ans << "\n";
    }
    //cout << s << "\n";
    for(int i=0;i<v[s].size();i++){
        if(b[v[s][i]] == 0){
            b[v[s][i]] =1;
            dfs(v[s][i],b,t);}
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n-1;i++){
        ll x,y;
        cin >> x >> y;
        v[x].pb(y);
    }

    bitset<NMAX+2> b;
    b.reset();
    for(int i=1;i<=n;i++){
        if(v[i].size() == 0){
            ans+=a[i];
            //cout << i << " ==> " << ans << "\n";
        }else{
            ans += a[i];
            dfs(i,b,a[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
