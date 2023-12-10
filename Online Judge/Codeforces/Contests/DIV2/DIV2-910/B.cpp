#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    long long last = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= last) {
            last = a[i];
            continue;
        }
        long long l = 1, r = INF, at = -1;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (a[i] / mid + (a[i] % mid > 0) <= last) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        assert(at != -1);
        ans += (at - 1);
        last = a[i] / at;
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