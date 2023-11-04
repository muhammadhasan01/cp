#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;
    int distToEnd = abs(n - x) + abs(m - y);
    if (distToEnd <= d) {
        cout << -1 << '\n';
        return;
    }
    int mostUp = max(1, x - d);
    int mostDown = min(n, x + d);
    int mostLeft = max(1, y - d);
    int mostRight = min(m, y + d);
    if (mostLeft != 1 && mostDown != n) {
        cout << n + m - 2 << '\n';
        return;
    }
    if (mostRight != m && mostUp != 1) {
        cout << n + m - 2 << '\n';
        return;
    }
    cout << -1 << '\n';
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