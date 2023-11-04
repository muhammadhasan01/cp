#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 1, j = n + n / 2 + 1; i <= n; i += 2, j--) {
        cout << i << " " << j << '\n';
    }
    for (int i = 2, j = 2 * n; i <= n; i += 2, j--) {
        cout << i << " " << j << '\n';
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