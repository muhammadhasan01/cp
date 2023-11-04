#include <bits/stdc++.h>

using namespace std;

void solve() {
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                ++cnt;
            }
        }
    }
    if (cnt == 0) {
        cout << 0 << '\n';
    } else if (cnt == 4) {
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