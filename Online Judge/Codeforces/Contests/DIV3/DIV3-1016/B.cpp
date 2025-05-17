#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int idx = -1;
    int n = (int) s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            idx = i;
        }
    }
    int ans = n - idx - 1;
    for (int i = 0; i < idx; i++) {
        if (s[i] != '0') {
            ans++;
        }
    }
    cout << ans << '\n';
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