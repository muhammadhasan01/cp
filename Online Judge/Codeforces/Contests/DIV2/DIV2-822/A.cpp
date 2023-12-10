#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = LLONG_MAX;
    for (int i = 0; i + 2 < n; i++) {
        ans = min(ans, a[i + 1] - a[i] + a[i + 2] - a[i + 1]);
        ans = min(ans, a[i + 2] - a[i] + a[i + 1] - a[i]);
        ans = min(ans, a[i + 2] - a[i + 1] + a[i + 2] - a[i]);
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