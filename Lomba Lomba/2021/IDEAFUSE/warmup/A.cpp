#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << max(0, 100 - a - b) << "  \n";   
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case #" << T << ": ";
        solve();
    }
    
    return 0;
}