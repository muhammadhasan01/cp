#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int cur = 4 * n - 4;
    if (k <= cur) {
        cout << (k + 1) / 2 << '\n';
        return;
    }
    cout << cur / 2 + (k - cur) << '\n';
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