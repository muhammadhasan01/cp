#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    string s(m, '0');
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            s[i] = '(';
        } else {
            s[i] = ')';
        }
    }
    cout << s << '\n';
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            s[j] = '(';
        }
        for (int j = i + 1; j <= 2 * i + 1; j++) {
            s[j] = ')';
        }
        cout << s << '\n';
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