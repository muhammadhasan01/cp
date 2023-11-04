#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long l = 1, r = n, ans = 1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (mid * (mid + 1) / 2 <= n) {
            ans = mid;
            l = mid + 1;
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