// Author : Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;
const int BAT = 1e5;

int n;
ll r;
ll ar[N], t[N], sar[N], st[N];
ll cnt;
vector<ll> ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        sar[i] = ar[i];
    }
    for (int i=1;i<=n;i++){
        cin >> t[i];
        st[i] = t[i];
        if (t[i] < ar[i]){
            cout << -1 << el;
            return 0;
        }
    }
    ll cur = 0;
    ll sisa = 0;
    for (int i=1;i<=n;i++){
        if (ar[i] <= sisa){
            sisa -= ar[i];
            cur += ar[i];
            continue;
        }
        cur += sisa;
        t[i] -= sisa;
        ar[i] -= sisa;
        sisa = 0;
        // ll kur = ar[i] - t[i] / 2LL;
        // if (kur <= 0){
        //     cur += ar[i] * 2LL;
        //     continue;
        // }
        ll ri = ar[i] * 2LL - t[i];
        if (ri <= 0){
            cur += ar[i] * 2LL;
            continue;
        }
        ll pos = ar[i] - ri;

        cur += pos * 2LL;
        cur += ri;
        ll bust = (ri + r - 1LL) / r;
        sisa = bust * r - ri;
        cnt += bust;
    }
    cout << cnt << el;
    if (cnt <= BAT){
        for (int i=1;i<=n;i++){
            ar[i] = sar[i];
            t[i] = st[i];
        }
        cur = 0;
        sisa = 0;
        for (int i=1;i<=n;i++){
            if (ar[i] <= sisa){
                sisa -= ar[i];
                cur += ar[i];
                continue;
            }
            cur += sisa;
            t[i] -= sisa;
            ar[i] -= sisa;
            sisa = 0;

            ll ri = ar[i] * 2LL - t[i];
            if (ri <= 0){
                cur += ar[i] * 2LL;
                continue;
            }
            ll pos = ar[i] - ri;

            cur += pos * 2LL;
            ll bust = (ri + r - 1LL) / r;
            for (ll jj=0;jj<bust;jj++){
                ans.pb(cur + jj * r);
            }
            cur += ri;
            sisa = bust * r - ri;
            cnt += bust;
        }
    }
    for (auto x : ans){
        cout << x << " ";
    }
    cout << el;

    return 0;
}