#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    long long cur = 1;
    while (cur < k) {
        cur = 2 * cur;
        ans++;
    }
    if (cur < n) {
        long long dif = n - cur;
        ans += (dif + k - 1) / k;
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