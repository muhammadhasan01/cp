#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int useless;
        cin >> useless;
    }
    if (n % 2 == 0) {
        cout << 2 << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 1 << ' ' << n << '\n';
        return;
    }
    cout << 4 << '\n';
    cout << 1 << ' ' << n << '\n';
    cout << 1 << ' ' << 2 << '\n';
    cout << 2 << ' ' << n << '\n';
    cout << 1 << ' ' << n << '\n';
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