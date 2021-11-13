#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, y, z;
    cin >> x >> y >> z;
    long long res = abs(x + y - z - z);
    cout << (res % 3 == 0 ? 0 : 1) << '\n';
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