#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    bool valid = false;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val == x) {
            valid = true;
        }
    }
    cout << (valid ? "YES" : "NO") << '\n';
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