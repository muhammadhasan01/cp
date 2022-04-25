#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> ok(n, false);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'R' && s[i] == 'B') {
            ok[i] = true;
        } else if (s[i - 1] == 'B' && s[i] == 'R') {
            ok[i] = true;
        } else if (s[i] == s[i - 1] && ok[i - 1]) {
            ok[i] = true;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i + 1] == 'R' && s[i] == 'B') {
            ok[i] = true;
        } else if (s[i + 1] == 'B' && s[i] == 'R') {
            ok[i] = true;
        } else if (s[i] == s[i + 1] && ok[i + 1]) {
            ok[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            continue;
        }
        if (!ok[i]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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