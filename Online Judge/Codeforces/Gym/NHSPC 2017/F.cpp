#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e16;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto can = [&](long long x) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min(x, a[i]);
        }
        return (sum / x) >= k;
    };
    long long l = 1, r = INF, ans = 0;
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
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}