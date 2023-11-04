#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && s[i - 1] == s[i]) {
            continue;
        }
        if (i + 1 < n && s[i + 1] == s[i]) {
            continue;
        }
        cout << "NO" << '\n';
        return;
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