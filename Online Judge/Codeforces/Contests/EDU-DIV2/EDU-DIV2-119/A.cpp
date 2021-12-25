#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (char cc : s) {
        if (cc == 'N') {
            ++cnt;
        }
    }
    cout << (cnt == 1 ? "NO" : "YES") << '\n';
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