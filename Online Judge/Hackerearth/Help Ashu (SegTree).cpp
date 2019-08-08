#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(n) for(int i=0;i<(int)n;i++)
#define forn(n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define csort(x,n) sort(x.begin()+1,x.begin()+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 100*1000;
int n,q;
ll t[2*NMAX+3];

void update(int idx, int val){
    for(t[idx+=n] = val; idx>1;idx/=2)t[idx/2] = t[idx]+t[idx^1];
}

ll query(int l, int r){
    ll ans = 0;
    for(l+=n,r+=n;l<r;l/=2,r/=2){
        if(l&1)ans+=t[l++];
        if(r&1)ans+=t[--r];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    form(n){
        cin >> t[i+n];
        t[i+n] &=1;
    }
    for(int i=n-1;i>0;i--){
        t[i] = t[2*i]+t[2*i+1];
    }
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        if(k == 0){
            ll idx, val;
            cin >> idx >> val;
            val&=1;
            update(idx-1,val);
        }else if(k == 1){
            int l,r;
            cin >> l >> r;
            cout << (r-l+1)-query(l-1,r) << "\n";
        }else if(k == 2){
            int l,r;
            cin >> l >> r;
            cout << query(l-1,r) << "\n";
        }
    }
    return 0;
}
