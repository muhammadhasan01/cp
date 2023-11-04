#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            ++cnt;
        } else if (x == 1) {
            ++one;
        }
    }
    int other = n - cnt;
    if (cnt <= other + 1) {
        cout << 0 << '\n';
        return;
    }
    if (one > 0 && one + cnt == n) {
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
    }
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