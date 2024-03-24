#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, n;
    cin >> x >> n;
    long long ans = 1;
    for (long long i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            long long j = x / i;
            if (i * n <= x) {
                ans = max(ans, __gcd(i, x - i * n));
            }
            if (j * n <= x) {
                ans = max(ans, __gcd(j, x - j * n));
            }
        }
    }
    cout << ans << '\n';
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