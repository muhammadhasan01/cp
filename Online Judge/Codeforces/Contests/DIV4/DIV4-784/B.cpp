#include <bits/stdc++.h>

using namespace std;

void solve() {
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (auto [e, c] : mp) {
        if (c >= 3) {
            cout << e << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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