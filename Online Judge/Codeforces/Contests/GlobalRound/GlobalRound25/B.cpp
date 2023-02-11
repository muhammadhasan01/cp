#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int mx = 0, g = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        g = __gcd(g, x);
    }
    cout << mx / g << '\n';
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