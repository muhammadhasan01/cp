#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = x;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, a[i] - a[i - 1]);
    }
    ans = max(ans, 2 * (a[n + 1] - a[n]));
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