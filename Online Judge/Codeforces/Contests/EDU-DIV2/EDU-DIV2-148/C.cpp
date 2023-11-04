#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (is_sorted(a.begin(), a.end()) && a[0] == a[n - 1]) {
        cout << 1 << '\n';
        return;
    }
    int ans = n;
    for (int i = 2; i < n; i++) {
        if (a[i - 2] <= a[i - 1] && a[i - 1] <= a[i]) {
            a[i - 1] = a[i - 2];
            --ans;
        } else if (a[i - 2] >= a[i - 1] && a[i - 1] >= a[i]) {
            a[i - 1] = a[i - 2];
            --ans;
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