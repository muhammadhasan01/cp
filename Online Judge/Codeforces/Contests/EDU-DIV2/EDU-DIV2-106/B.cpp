#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (is_sorted(s.begin(), s.end())) {
        cout << "YES" << '\n';
        return;
    }   
    for (int i = 1; i < n; i++) {
        if (s[i] == '1' && s[i] == s[i - 1]) {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '0' && s[j] == s[j - 1]) {
                    cout << "NO" << '\n';
                    return;
                }
            }
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