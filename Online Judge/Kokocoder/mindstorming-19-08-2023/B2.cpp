#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    int ans = 0;
    for (int l = 0, r = n - 1; l <= r; ) {
        if (sum <= 0) {
            sum += a[l++];
        } else {
            sum -= a[r--];
        }
        if (sum == 0) {
            ans = max(ans, l + n - r - 1);
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