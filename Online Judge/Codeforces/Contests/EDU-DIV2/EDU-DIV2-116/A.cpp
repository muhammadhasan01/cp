#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int ab = 0;
    int ba = 0;
    int n = s.length();
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            continue;
        }
        if (s[i] == 'a') {
            ba++;
        } else if (s[i] == 'b') {
            ab++;
        }
    }
    auto conv = [&](char& cc) -> void {
        if (cc == 'a') {
            cc = 'b';
        } else {
            cc = 'a';
        }
    };
    if (ab != ba) {
        conv(s[0]);
    }
    cout << s << '\n';
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