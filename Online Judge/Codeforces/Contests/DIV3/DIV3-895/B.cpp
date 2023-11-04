#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        int d, s;
        cin >> d >> s;
        s = (s + 1) / 2;
        mn = min(mn, d + s);
    }
    cout << max(1, mn - 1) << '\n';
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