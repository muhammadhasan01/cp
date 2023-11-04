#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (__gcd(a, b) == 1) {
        cout << 1 << "\n";
        cout << a << " " << b << '\n';
        return;
    }
    cout << 2 << "\n";
    cout << 1 << " " << b - 1 << '\n';
    cout << a << " " << b << '\n';
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