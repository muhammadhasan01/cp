#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    c = 2 * c;
    int dif = abs(a - b);
    cout << (dif + c - 1) / c << '\n';
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