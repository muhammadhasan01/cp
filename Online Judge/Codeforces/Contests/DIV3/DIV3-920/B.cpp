#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, f;
    cin >> s >> f;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && f[i] == '0') {
            x++;
        } else if (s[i] == '0' && f[i] == '1') {
            y++;
        }
    }
    cout << max(x, y) << '\n';
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