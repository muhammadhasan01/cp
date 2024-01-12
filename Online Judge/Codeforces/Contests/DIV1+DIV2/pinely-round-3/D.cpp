#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a[n - 1]) {
        cout << 0 << '\n';
        return;
    }
    long long g = 0;
    for (int i = 0; i < n; i++) {
        a[i] -= k;
        g = __gcd(g, a[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long need = a[i] / g;
        if (need <= 0) {
            cout << -1 << '\n';
            return;
        }
        ans += (need - 1);
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