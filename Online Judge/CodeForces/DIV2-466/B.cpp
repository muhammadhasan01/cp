#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, k, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> k >> a >> b;

    if (k == 1) {
        cout << (x - 1) * a << '\n';
        return 0;
    }

    ll ans = 0;
    while (x > 1) {
        if (x % k == 0) {
            ll g = x / k;
            ans += min((x - g) * a, b);
            x /= k;
        } else {
            if (x < k) {
                ans += (x - 1) * a;
                break;
            } else {
                ans += (x % k) * a;
                x -= (x % k);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
