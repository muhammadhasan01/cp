#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, P, L, t;
    cin >> n >> P >> L >> t;
    long long slot = (n + 6) / 7;

    auto can = [&](long long x) -> bool {
        long long p = x * L + min(slot, 2 * x) * t;
        return p >= P;
    };

    long long l = 1, r = n, at = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            at = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << n - at << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}