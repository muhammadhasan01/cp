#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (a[0] != n) {
        cout << "NO" << '\n';
        return;
    }
    vector<int> b(n);
    for (int x = 1, r = n - 1; x <= n; x++) {
        while (a[r] < x) {
            r--;
        }
        b[x - 1] = r + 1;
    }
    cout << (a == b ? "YES" : "NO") << '\n';
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