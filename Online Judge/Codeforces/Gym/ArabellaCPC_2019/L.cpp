#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const ll MOD = 1e9 + 7;

ll n, m, r, c;
ll backr, backc;
ll jump;
ll gnr, gmc;
ll ans;

ll fpow(ll a, ll b){
    if (b==0) return 1;
    ll temp = fpow(a, b/2);
    temp = (temp * temp) % MOD;
    if (b & 1){
        temp = temp * a % MOD;
    }
    return temp;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r >> c;
    gnr = __gcd(n, r);
    gmc = __gcd(m, c);
    backr = n / gnr;
    backc = m / gmc;

    jump = backr * backc / __gcd(backr, backc);

    ll inv = fpow(2, MOD-2);
    ans = ((gnr+n-2)%MOD * (n/gnr) % MOD) % MOD * inv % MOD;
    ans = ans * m % MOD;
    ans = ans * (jump / backr)  % MOD;
    ans += (gmc+m)%MOD * (m/gmc) % MOD * (jump / backc) % MOD * inv % MOD;
    cout << ans % MOD << el;

    return 0;
}
