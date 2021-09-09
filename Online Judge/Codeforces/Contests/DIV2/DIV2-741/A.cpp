#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long l, r;
    cin >> l >> r;
    long long p = max(l, r / 2 + 1);
    cout << r % p << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    
    return 0;
}