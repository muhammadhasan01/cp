#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    if (x != 0) {
        cout << -1 << '\n';
        return;
    }
    if (y == 0) {
        cout << -1 << '\n';
        return;
    }
    if ((n - 1) % y != 0) {
        cout << -1 << '\n';
        return;
    }
    int cur = 2;
    for (int i = 0; i < n - 1; i++) {
        if (i > 0 && i % y == 0) {
            cur += y;
        }
        cout << cur << " \n"[i == n - 2];
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