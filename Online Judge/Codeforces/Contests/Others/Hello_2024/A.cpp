#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    cout << ((a + b) & 1 ? "Alice" : "Bob") << '\n';
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