#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = (int) s.length();
    for (int i = 0; i + 1 < n; i++) {
        if (s[i + 1] == '0') {
            continue;
        }
        long long L = stoi(s.substr(0, i + 1));
        long long R = stoi(s.substr(i + 1));
        if (L < R) {
            cout << L << ' ' << R << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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