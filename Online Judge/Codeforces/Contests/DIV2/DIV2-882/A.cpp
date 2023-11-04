#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dif(n - 1);
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        dif[i] = abs(a[i] - a[i + 1]);
        ans += dif[i];
    }
    sort(dif.rbegin(), dif.rend());
    for (int i = 0; i < k - 1; i++) {
        ans -= dif[i];
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