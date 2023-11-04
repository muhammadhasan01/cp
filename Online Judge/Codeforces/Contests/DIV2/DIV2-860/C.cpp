#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    long long X = a[0] * b[0], Y = b[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        X = __gcd(X, a[i] * b[i]);
        Y = Y * (b[i] / __gcd(b[i], Y));
        if (X % Y != 0) {
            ++ans;
            X = a[i] * b[i];
            Y = b[i];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        solve();
    }
    
    return 0;
}