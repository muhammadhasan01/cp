#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const long long M = 1e9 + 7;
ll a, b;
int k;

ll fast(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return (ret % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> k;
    if (a < b) swap(a, b);
    if (b == 1) {
        if (k == -1) {
            cout << (a & 1 ? 1 : 0) << '\n';
        } else {
            cout << 1 << '\n';
        }
    } else {
        if (abs(a - b) & 1 && k == -1) {
            cout << 0 << '\n';
        } else {
            ll g = fast(2, a - 1);
            cout << fast(g, b - 1) << '\n';
        }
    }

    return 0;
}
