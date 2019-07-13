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

int q;
ll ans[30];
ll pre[30];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll k = 2;
    forn(i,1,27){
        k *= 2;
        pre[i] = k-1;
        ans[i] = 1;
        for(ll j=2;j*j<=k-1;j++){
            if((k-1)%j == 0){
                ans[i] = (k-1)/j;
                break;
            }
        }
    }

    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        auto it = lower_bound(pre+1,pre+27,x);
        auto it2 = upper_bound(pre+1,pre+27,x);
        if(it == it2){
            cout << *it << "\n";
        }else{
            int pos = it - pre;
            cout << ans[pos] << "\n";
        }
    }

    return 0;
}
