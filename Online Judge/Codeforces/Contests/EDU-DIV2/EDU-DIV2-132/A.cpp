#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x;
    cin >> x;
    vector<int> a(4);
    for (int i = 1; i <= 3; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    int u = x;
    while (cnt < 2) {
        if (a[u] == 0) {
            cout << "NO" << '\n';
            return;
        }
        ++cnt;
        u = a[u];
    }
    cout << "YES" << '\n';
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