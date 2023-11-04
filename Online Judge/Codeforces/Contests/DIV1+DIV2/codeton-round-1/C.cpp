#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool isOne = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            isOne = true;
        }
    }
    if (!isOne) {
        cout << "YES" << '\n';
        return;
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    reverse(a.begin(), a.end());
    int m = (int) a.size();
    for (int i = 0; i + 1 < m; i++) {
        if (a[i] - a[i + 1] == 1) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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