#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s == "^") {
        cout << 1 << '\n';
        return;
    }
    
    int n = s.length();
    int ans = 0;
    if (s[0] == '_') {
        ++ans;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') {
            if (i + 1 < n && s[i + 1] == '^') {
                continue;
            }
            ++ans;
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