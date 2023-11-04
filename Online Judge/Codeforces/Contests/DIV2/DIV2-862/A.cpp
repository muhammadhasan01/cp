#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            a[i] = (a[i] ^ a[i - 1]);
        }
    }
    if (n % 2 == 0) {
        if (a[n - 1] == 0) {
            cout << 0 << '\n';
            return;
        }
        cout << -1 << '\n';
        return;
    }
    cout << a[n - 1] << '\n';
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