#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    int cnt = 0;
    for (char cc : s) {
        if (cc == c) {
            cnt++;
        }
    }
    if (cnt == n) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = i; j <= n; j += i) {
            if (s[j - 1] != c) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << 1 << '\n';
            cout << i << '\n';
            return;
        }
    }
    cout << 2 << '\n';
    cout << n << " " << n - 1 << '\n';
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