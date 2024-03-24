#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> w(3);
    for (int i = 0; i < 3; i++) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    cout << (w[1] - w[0] == w[2] - w[1] ? "Yes" : "No") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}