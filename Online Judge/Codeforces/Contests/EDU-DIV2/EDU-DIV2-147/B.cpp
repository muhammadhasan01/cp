#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (l == -1) {
                l = i;
            }
            r = i;
        }
    }
    int mn = a[l], mx = a[l];
    for (int i = l; i <= r; i++) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    while (l > 0) {
        if (a[l - 1] <= mn) {
            l--;
        } else {
            break;
        }
        mn = min(mn, a[l]);
    }
    while (r + 1 < n) {
        if (a[r + 1] >= mx) {
            r++;
        } else {
            break;
        }
        mx = max(mx, a[r]);
    }
    cout << l + 1 << ' ' << r + 1 << '\n';
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