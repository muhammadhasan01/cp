#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int B = 0;
    for (char cc : s) {
        if (cc == 'B') {
            ++B;
        }
    }
    if (B == k) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        for (char cc : {'A', 'B'}) {
            string p = s;
            for (int j = 0; j <= i; j++) {
                p[j] = cc;
            }
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (p[j] == 'B') {
                    ++cnt;
                }
            }
            if (cnt == k) {
                cout << 1 << '\n';
                cout << i + 1 << ' ' << cc << '\n';
                return;
            }
        }
    }
    cout << 2 << '\n';
    cout << n << ' ' << 'A' << '\n';
    cout << k << ' ' << 'B' << '\n';
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