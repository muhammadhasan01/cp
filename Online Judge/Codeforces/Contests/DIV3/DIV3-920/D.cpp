#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    long long A = 0, B = 0;
    for (int i = 0; i < n; i++) {
        A += a[i];
        B -= b[i];
    }
    ans = max(ans, A + B);
    for (int i = 0, l = n - 1, r = m - 1; i < n; i++, l--, r--) {
        A -= a[i] * 2;
        B += b[l] + b[r];
        ans = max(ans, A + B);
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