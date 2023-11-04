#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if (x >= y) {
        cout << x << '\n';
        return;
    }
    int pos = min(y, x + k);
    int res = pos + 2 * (y - pos);
    cout << res << '\n';
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