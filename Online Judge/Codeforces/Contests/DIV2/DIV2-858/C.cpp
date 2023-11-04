#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << abs(a[0] - a[1]) << '\n';
        return;
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans += abs(a[i]);
    }
    if (n == 2) {
        long long res = 0;
        for (int i = 0; i < m; i++) {
            res += abs(a[i] - 2);
        }
        ans = min(ans, res);
    }
    if (n % 2 == 0) {
        vector<long long> pref(m);
        for (int i = 0; i < m; i++) {
            pref[i] = abs(-1 - a[i]);
            if (i > 0) {
                pref[i] += pref[i - 1];
            }
        }
        long long sum = 0;
        for (int i = m - 1; i >= 0; i--) {
            long long cur = sum + abs(n - a[i]) + (i > 0 ? pref[i - 1] : 0);
            ans = min(ans, cur);
            sum += abs(-1 - a[i]);
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