#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n <= 6 || n == 9) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    int rem = n % 3;
    if (rem == 0) {
        cout << 1 << " " << 4 << " " << n - 5 << '\n';
    } else {
        cout << 1 << " " << 2 << " " << n - 3 << '\n';
    }
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