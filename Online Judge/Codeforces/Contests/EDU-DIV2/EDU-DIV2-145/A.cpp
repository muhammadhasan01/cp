#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[3]) {
        cout << -1 << '\n';
        return;
    }
    map<char, int> mp;
    int mx = 0;
    for (char cc : s) {
        mx = max(mx, ++mp[cc]);
    }
    cout << (mx == 3 ? 6 : 4) << '\n';
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