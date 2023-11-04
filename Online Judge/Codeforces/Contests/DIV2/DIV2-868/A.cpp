#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int need = n * (n - 1) / 2 - k;
    for (int x = 0; x <= n; x++) {
        int y = n - x;
        if (x * y == need) {
            cout << "YES" << '\n';
            for (int j = 0; j < x; j++) {
                cout << 1 << ' ';
            }
            for (int j = 0; j < y; j++) {
                cout << -1 << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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