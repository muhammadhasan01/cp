#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int fst = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            fst = i;
            break;
        }
    }
    if (fst == -1) {
        cout << 0 << '\n';
        return;
    }
    int lst = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            lst = i;
            break;
        }
    }
    for (int i = fst; i <= lst; i++) {
        if (s[i] == '1') {
            cout << 2 << '\n';
            return;
        }
    }
    cout << 1 << '\n';
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