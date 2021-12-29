#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dr = 1, dc = 1;
    int ans = 0;
    while (1) {
        if (rb == rd || cb == cd) {
            break;
        }
        if (rb + dr > n) {
            dr = -dr;
        } else if (rb + dr < 1) {
            dr = -dr;
        }
        if (cb + dc > m) {
            dc = -dc;
        } else if (cb + dc < 1) {
            dc = -dc;
        }
        ++ans;
        rb += dr;
        cb += dc;
    }
    cout << ans << '\n';
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