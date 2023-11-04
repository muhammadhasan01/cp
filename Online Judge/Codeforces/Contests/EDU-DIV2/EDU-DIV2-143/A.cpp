#include <bits/stdc++.h>

using namespace std;

void solve() {
    auto check = [&](string s) -> bool {
        int len = s.length();
        for (int i = 1; i < len; i++) {
            if (s[i] == s[i - 1]) {
                return false;
            }
        }
        return true;
    };

    int n, m;
    cin >> n >> m;
    string s, p;
    cin >> s >> p;
    if (check(s)) {
        if (check(p)) {
            cout << "YES" << '\n';
            return;
        }
        if (s[n - 1] == p[m - 1]) {
            cout << "NO" << '\n';
            return;
        }
        int pos = -1;
        for (int i = 1; i < m; i++) {
            if (p[i] == p[i - 1]) {
                pos = i;
                break;
            }
        }
        if (check(p.substr(pos))) {
            cout << "YES" << '\n';
            return;
        }
    } else {
        if (!check(p)) {
            cout << "NO" << '\n';
            return;
        }
        if (s[n - 1] == p[m - 1]) {
            cout << "NO" << '\n';
            return;
        }
        int pos = -1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                pos = i;
                break;
            }
        }
        if (check(s.substr(pos))) {
            cout << "YES" << '\n';
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