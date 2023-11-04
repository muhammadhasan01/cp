#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char mn = 'z';
    for (char cc : s) {
        mn = min(mn, cc);
    }
    int pos = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == mn) {
            pos = i;
            break;
        }
    }
    cout << mn;
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            continue;
        }
        cout << s[i];
    }
    cout << '\n';
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