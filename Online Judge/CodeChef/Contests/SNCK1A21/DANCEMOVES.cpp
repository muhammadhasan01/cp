#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int dif = abs(x - y);
    if (y <= x) {
        cout << dif << '\n';
    } else {
        if (dif % 2 == 0) {
            cout << dif / 2 << '\n';
        } else {
            cout << 1 + abs(y - (x - 1)) / 2 << '\n';
        }
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