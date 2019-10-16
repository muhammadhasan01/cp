#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int q;
ll n,m;

ll cl(ll a, ll b) {
    return (a + b - 1)/b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;

    ll gcd = __gcd(n, m);
    ll gn = n/gcd, gm = m/gcd;

    while (q--) {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        ll sec1 = cl(sy, (sx == 1 ? gn : gm));
        ll sec2 = cl(ey, (ex == 1 ? gn : gm));
        puts(sec1 == sec2 ? "YES" : "NO");
    }

    return 0;
}
