#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s.length() == 2) {
        cout << s.back() << '\n';
    } else {
        cout << *min_element(s.begin(), s.end()) << '\n';
    }
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