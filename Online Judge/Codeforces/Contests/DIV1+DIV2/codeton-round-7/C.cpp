#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a[i] = {val, i};
    }
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        b[i] = {val, i};
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> ans(n);
    for (int i = n - x, j = 0; i < n && j < n; i++, j++) {
        if (a[i].first <= b[j].first) {
            cout << "NO" << '\n';
            return;
        }
        ans[a[i].second] = b[j].first;
    }
    for (int i = 0, j = x; i < n && j < n; i++, j++) {
        if (a[i].first > b[j].first) {
            cout << "NO" << '\n';
            return;
        }
        ans[a[i].second] = b[j].first;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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