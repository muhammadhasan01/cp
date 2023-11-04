#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d < b) {
        cout << "-1" << '\n';
        return;
    }
    int dif = d - b;
    a += dif;
    b += dif;
    if (a < c) {
        cout << -1 << '\n';
        return;
    }
    cout << dif + a - c << '\n';
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