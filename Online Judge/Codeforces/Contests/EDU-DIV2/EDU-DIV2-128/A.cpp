#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int x = 1; x <= 50; x++) {
        if (a <= x && x <= b && c <= x && x <= d) {
            cout << x << "\n";
            return;
        }
    }
    cout << a + c << "\n";
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