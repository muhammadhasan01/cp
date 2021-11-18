#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, s;
    cin >> n >> s;
    long long med = (n + 1) / 2;
    long long len = (n - med + 1);
    long long l = 0, r = s, ans = 0;
    auto can = [&](long long x) -> bool {
        return x * len <= s;
    };
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
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}