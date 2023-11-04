#include <bits/stdc++.h>

using namespace std;
void solve() {
    long long x;
    cin >> x;
    long long l = 1, r = 1e9, ans = 1e18;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (mid * mid >= x) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans - 1 << '\n';
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