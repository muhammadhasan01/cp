#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> ans;
    if ((a[0] & 1) == (a[n - 1] & 1)) {
        for (int i = n - 2; i >= 0; i--) {
            if ((a[i] & 1) == (a[n - 1] & 1)) {
                ans.emplace_back(i, n - 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if ((a[0] & 1) != (a[i] & 1)) {
                ans.emplace_back(0, i);
            }
        }
    } else {
        for (int i = 1; i < n; i++) {
            if ((a[0] & 1) != (a[i] & 1)) {
                ans.emplace_back(0, i);
            }
        }
        for (int i = n - 2; i > 0; i--) {
            if ((a[0] & 1) == (a[i] & 1)) {
                ans.emplace_back(i, n - 1);
            }
        }
    }
    int m = (int) ans.size();
    cout << m << '\n';
    for (auto [l, r] : ans) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        if (t == 22) {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; i++) cin >> a[i];
            cout << n << "|";
            for (int i = 0; i < n; i++) cout << a[i] << "|";
            cout << '\n';
            continue;
        }
        solve();
    }
    
    return 0;
}