#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 1) {
        int m = n / 2;
        cout << 1 << " " << m << " " << m << '\n';
        return;
    }
    int m = n / 2;
    if (m % 2 == 0) {
        cout << m / 2 << " " << m / 2 << " " << m << '\n';
        return;
    }
    cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2 << '\n';
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