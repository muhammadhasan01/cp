#include <bits/stdc++.h>

using namespace std;

const long long M = 1e8;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << a + b * M << ' ' << b << ' ' << c << '\n';
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