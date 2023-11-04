#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    x = abs(x), y = abs(y);
    if (x < y) {
        swap(x, y);
    }
    int res = 2  * y;
    x -= y;
    res += max(0, 2 * x - 1);
    cout << res << '\n';
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