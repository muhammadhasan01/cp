#include <bits/stdc++.h>

using namespace std;

const string RB = "RB";

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int walk = (n - 1) + (m - 1);
    int color = -1;
    bool valid = false;
    for (int w : {walk, walk + 2}) {
        ++color;
        if (k >= w && (k - w) % 4 == 0) {
            valid = true;
            break;
        }
    }
    if (!valid) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int j = 0; j < m - 1; j++) {
        cout << RB[color] << " \n"[j == m - 2];
        color ^= 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            cout << "R" << " \n"[j == m - 2];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (j < m - 1) {
                cout << "B ";
            } else {
                cout << RB[color] << '\n';
                color ^= 1;
            }
        }
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