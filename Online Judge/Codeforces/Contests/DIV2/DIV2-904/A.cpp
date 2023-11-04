#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, k;
    cin >> x >> k;
    while (true) {
        string s = to_string(x);
        int sum = 0;
        for (char cc : s) {
            sum += (cc - '0');
            sum %= k;
        }
        if (sum == 0) {
            cout << x << '\n';
            return;
        }
        x++;
    }
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