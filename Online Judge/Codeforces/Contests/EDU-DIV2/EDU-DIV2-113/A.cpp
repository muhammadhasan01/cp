#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'a' && s[i - 1] == 'b') {
            cout << i << ' ' << i + 1 << '\n';
            return;
        }
        if (s[i] == 'b' && s[i - 1] == 'a') {
            cout << i << ' ' << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << ' ' << -1 << '\n';
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