#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long ans = 0;
    int L = INT_MAX, R = -INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            swap(a[i], b[i]);
        }
        L = min(L, a[i]);
        R = max(R, b[i]);
        ans += a[i] - b[i];
    }
    if (L < R) {
        ans += 2LL * (R - L);
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