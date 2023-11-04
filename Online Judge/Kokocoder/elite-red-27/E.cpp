#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    m = m + 1;
    int ans = 0;
    for (int k = 30; k >= 0 && n <= m; k--) {
        if ((n >> k & 1) == (m >> k & 1)) {
            continue;
        }
        if (m >> k & 1) {
            ans |= 1 << k;
            n |= 1 << k;
        }
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