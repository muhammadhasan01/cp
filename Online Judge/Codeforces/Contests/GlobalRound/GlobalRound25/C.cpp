#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    if (a[0] == a[n - 1]) {
        cout << n / 2 << '\n';
        return;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            ans = max(ans, 1LL * i * (n - i));
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