#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 2) {
        cout << max(a[0] + a[1], abs(a[0] - a[1]) * 2) << '\n';
        return;
    }
    long long maks = *max_element(a.begin(), a.end());
    if (n == 3 && a[0] != maks && a[2] != maks) {
        long long res = a[0] + a[1] + a[2];
        res = max(res, abs(a[2] - a[0]) * 3);
        res = max(res, abs(a[1] - a[0]) * 2 + a[2]);
        res = max(res, abs(a[1] - a[2]) * 2 + a[0]);
        res = max(res, abs(abs(a[1] - a[0]) - a[2]) * 3);
        res = max(res, abs(abs(a[1] - a[2]) - a[0]) * 3);
        res = max(res, abs(a[1] - a[0]) * 3);
        res = max(res, abs(a[1] - a[2]) * 3);
        res = max(res, a[0] * 3);
        res = max(res, a[2] * 3);
        cout << res << '\n';
        return;
    }
    cout << 1LL * maks * n << '\n';
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