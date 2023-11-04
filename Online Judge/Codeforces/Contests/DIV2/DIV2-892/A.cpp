#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == a[n - 1]) {
        cout << -1 << '\n';
        return;
    }
    vector<int> b, c;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[n - 1]) {
            b.emplace_back(a[i]);
        } else {
            c.emplace_back(a[i]);
        }
    }
    int lb = (int) b.size();
    int lc = (int) c.size();
    cout << lb << ' ' << lc << '\n';
    for (int i = 0; i < lb; i++) {
        cout << b[i] << " \n"[i == lb - 1];
    }
    for (int i = 0; i < lc; i++) {
        cout << c[i] << " \n"[i == lc - 1];
    }
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