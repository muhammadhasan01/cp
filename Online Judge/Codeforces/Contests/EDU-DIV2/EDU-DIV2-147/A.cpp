#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s[0] == '0') {
        cout << 0 << '\n';
        return;
    }
    int n = s.length();
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (i == 0) {
                ans = ans * 9;
            } else {
                ans = ans * 10;
            }
        }
    }
    cout << ans << '\n';
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