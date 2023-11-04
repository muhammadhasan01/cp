#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool isDif = false;
    bool sameAfterDif = false;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            if (sameAfterDif) {
                cout << "No" << '\n';
                return;
            }
            isDif = true;
        } else {
            if (isDif) {
                sameAfterDif = true;
            }
        }
    }
    cout << "Yes" << '\n';
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