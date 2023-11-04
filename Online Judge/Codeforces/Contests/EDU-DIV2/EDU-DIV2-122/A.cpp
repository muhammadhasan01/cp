#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 7 == 0) {
        cout << n << '\n';
        return;
    }
    string s = to_string(n);
    for (char x = '0'; x <= '9'; x++) {
        s.back() = x;
        if (stoi(s) % 7 == 0) {
            cout << s << '\n';
            return;
        }
    }
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