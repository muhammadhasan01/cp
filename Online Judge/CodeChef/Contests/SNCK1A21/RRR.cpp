#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    n = n - 1;
    long long pos = n - k + 1;
    auto can = [&](long long x) -> bool {
        return (n - x) >= (x - pos);
    };
    long long l = pos, r = n, at = pos;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            at = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << 2 * at << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}