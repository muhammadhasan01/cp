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
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    cout << a[0] << ' ';
    for (int i = n - 1; i >= 1; i--) {
        cout << a[i] << " \n"[i == 1];
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