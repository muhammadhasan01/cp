#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long h;
    cin >> n >> h;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long x = a[0], y = a[1];
    long long z = x + y;
    long long d = h / z;
    long long rem = h - d * z;
    long long ans = 2 * d;
    if (rem > 0) {
        if (rem <= x) {
            ans += 1;
        } else if (rem > x) {
            ans += 2;
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