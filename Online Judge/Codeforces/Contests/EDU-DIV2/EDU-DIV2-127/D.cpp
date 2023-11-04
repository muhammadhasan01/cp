#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(a[i] - a[i - 1]);
    }
    auto [mn, mx] = minmax_element(a.begin(), a.end());
    if (*mn > 1) {
        long long lft = a[0] - 1;
        long long mid = (*mn - 1) * 2LL;
        long long rgt = a[n - 1] - 1;
        ans += min({lft, mid, rgt});
    }
    if (x > *mx) {
        long long lft = x - a[0];
        long long mid = (x - *mx) * 2LL;
        long long rgt = x - a[n - 1];
        ans += min({lft, mid, rgt});
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