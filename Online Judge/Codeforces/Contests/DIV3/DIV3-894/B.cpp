#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b = {a[0]};
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {
            b.emplace_back(a[i]);
        } else {
            b.emplace_back(a[i]);
            b.emplace_back(a[i]);
        }
    }
    int m = (int) b.size();
    cout << m << '\n';
    for (int i = 0; i < m; i++) {
        cout << b[i] << " \n"[i == m - 1];
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