#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]] = i;
    }
    if (mp['R'] < mp['r'] || mp['G'] < mp['g'] || mp['B'] < mp['b']) {
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