#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (x == 1) {
        cout << "YES" << '\n';
        return;
    }
    if (x == n) {
        cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
        return;
    }
    int y = n - x;
    int mid = (n + 1) / 2;
    if (y >= mid) {
        cout << "YES" << '\n';
        return;
    }
    vector<int> b;
    for (int i = 0; i < y; i++) {
        b.emplace_back(a[i]);
    }
    for (int i = n - y; i < n; i++) {
        b.emplace_back(a[i]);
    }
    sort(b.begin(), b.end());
    int idx = 0;
    for (int i = 0; i < y; i++) {
        a[i] = b[idx++];
    }
    for (int i = n - y; i < n; i++) {
        a[i] = b[idx++];
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
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