#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    if (is_sorted(p.begin(), p.end())) {
        cout << 0 << '\n';
        return;
    }
    if (p[0] == 1 || p[n - 1] == n) {
        cout << 1 << '\n';
        return;
    }
    if (p[0] == n && p[n - 1] == 1) {
        cout << 3 << '\n';
        return;
    }
    cout << 2 << '\n';
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