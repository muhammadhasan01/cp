#include <bits/stdc++.h>

using namespace std;

const long long N = 2e9;
const long long INF = N * (N - 1) / 2 + 5;

int tc;
long long n;

bool can(long long x) {
    long long add = x - (n - 1);
    long long l = 2, r = N, at = 2;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        long long res = mid * (mid - 1) / 2 - (mid - 1);
        if (res >= add) {
            r = mid - 1;
            at = mid;
        } else {
            l = mid + 1;
        }
    }
    long long bridge = n - at;
    return (bridge >= (x + 1) / 2);
}

void solve() {
    cin >> n;
    long long l = n - 1, r = INF, ans = n - 1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}