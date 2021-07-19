#include <bits/stdc++.h>

using namespace std;

void solve() {  
    string str;
    cin >> str;
    char cc = '0';
    for (char e : str) {
        cc = max(cc, e);
    }
    cout << cc << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}