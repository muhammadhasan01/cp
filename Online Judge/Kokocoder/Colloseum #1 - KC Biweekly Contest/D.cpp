#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long h, l;
    cin >> h >> l;
    long long node = 1;
    for (int i = 1; i < h; i++) {
        if (l & 1) {
            l = l / 2 + 1;
            node = node * 2;
        } else {
            l = l / 2;
            node = node * 2 + 1;
        }
    }
    cout << node << '\n';
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