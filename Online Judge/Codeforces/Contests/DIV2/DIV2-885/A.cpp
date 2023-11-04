#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int sx, sy;
    cin >> sx >> sy;
    int val = (sx + sy) % 2;
    bool ok = true;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        int cur = (x + y) % 2;
        if (val == cur) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
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