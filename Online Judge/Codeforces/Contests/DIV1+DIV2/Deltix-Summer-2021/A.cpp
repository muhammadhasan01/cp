#include <bits/stdc++.h>

using namespace std;

void solve() {
    int c, d;
    cin >> c >> d;
    if (c == 0 && d == 0) {
        cout << 0 << '\n';
    } else {
        if (c % 2 != d % 2) {
            cout << -1 << '\n';
        } else {
            cout << (c == d ? 1 : 2) << '\n';
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