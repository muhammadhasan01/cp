#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    long long len;
    int n;
    cin >> len >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto can = [&](long long x) {
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            long long need = max(0LL, a[i] - 1 - cur);
            if (x < need) {
                return false;
            }
            cur = a[i] + x / 2;
        }
        return cur >= len;
    };
    long long l = 0, r = INF, ans = 0;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}