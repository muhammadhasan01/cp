#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int n,m;
ll a[N], b[N], pa[N], sb[N];

ll f(ll x){
    ll ret = 0;
    int pos = upper_bound(a+1,a+1+n,x) - a - 1;
    ret += (x * (ll)pos) - pa[pos];
    int spos = lower_bound(b+1,b+1+m,x) - b;
    ret += sb[spos] - (x * (ll)(m - spos + 1)) ;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
    }

    sort(a+1,a+1+n);
    sort(b+1,b+1+m);

    for(int i=1;i<=n;i++){
        pa[i] = pa[i-1] + a[i];
    }

    for(int i=m;i>=1;i--){
        sb[i] = sb[i+1] + b[i];
    }

    ll l = 0, r = 1e9;
    while(r - l >= 3){
        ll m1 = l + (r - l)/3;
        ll m2 = r - (r - l)/3;
        if(f(m1) > f(m2)){
            l = m1;
        }else{
            r = m2;
        }
    }
    ll ans = 1e18;
    for(ll i=l;i<=r;i++){
        ans = min(ans,f(i));
    }
    cout << ans << '\n';

    return 0;
}
