#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            bool isExist = false;
            for (auto [dx, dy] : {make_pair(1, 2), make_pair(2, 1)}) {
                for (int cx : {x + dx, x - dx}) {
                    for (int cy : {y + dy, y - dy}) {
                        if (cx < 1 || cx > n || cy < 1 || cy > m) {
                            continue;
                        }
                        isExist = true;
                        break;
                    }
                    if (isExist) {
                        break;
                    }
                }
                if (isExist) {
                    break;
                }
            }
            if (isExist) {
                continue;
            }
            cout << x << ' ' << y << '\n';
            return;
        }
    }
    cout << 1 << ' ' << 1 << '\n';
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