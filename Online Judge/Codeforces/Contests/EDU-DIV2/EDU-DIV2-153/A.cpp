#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int m = s.length();
    int n = 2 * m;
    string X = "";
    for (int i = 0; i < n; i++) {
        if (i < m) {
            X += "(";
        } else {
            X += ")";
        }
    }
    string Y = "";
    for (int i = 0; i < n; i += 2) {
        Y += "()";
    }
    for (string str : {X, Y}) {
        bool ok = true;
        for (int i = 0; i <= m; i++) {
            if (str.substr(i, m) == s) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << '\n';
            cout << str << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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