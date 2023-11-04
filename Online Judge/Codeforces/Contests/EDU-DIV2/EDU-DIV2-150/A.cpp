#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << (n > 4 ? "Alice" : "Bob") << '\n';
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