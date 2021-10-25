#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, k;
    cin >> x >> k;
    long long m = x * k;
    cout << x + x << " " << (m - 1) * m << '\n';
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