#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 5;

ll n;
pair<ll, ll> best;

ll powz(ll x) {
    return x * x * x;
}

void DP(ll m, ll steps, ll substracted) {
    if (m == 0) {
        best = max(best, make_pair(steps, substracted));
        return;
    }
    ll l = 1, r = N, x = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (powz(mid) <= m) {
            l = mid + 1;
            x = mid;
        } else {
            r = mid - 1;
        }
    }
    DP(m - powz(x), steps + 1, substracted + powz(x));
    DP(powz(x) - 1 - powz(x - 1), steps + 1, substracted + powz(x - 1));
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    DP(n, 0LL, 0LL);
    cout << best.first << " " << best.second << '\n';

    return 0;
}