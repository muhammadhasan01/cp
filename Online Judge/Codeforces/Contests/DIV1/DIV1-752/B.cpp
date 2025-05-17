#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;
    if (y % x == 0) {
        cout << x << '\n';
        return;
    }
    if (y < x) {
        cout << x + y << '\n';
        return;
    }
    long long rem = y % x;
    cout << y - rem / 2 << '\n';
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