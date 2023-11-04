#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[n - 1] - a[0] + a[m - 1] - a[n] << '\n';
    for (int i = n - 1, j = n; j < m; i--, j++) {
        cout << a[i] << " " << a[j] << '\n';
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