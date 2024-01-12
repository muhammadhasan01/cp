#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (a == 1) {
        cout << b * b << '\n';
        return;
    }
    long long res = a * (b / __gcd(a, b));
    if (res == b) {
        res *= (b / a);
    }
    cout << res << '\n';
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