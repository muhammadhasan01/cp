#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n % 2 == 1) {
        cout << "YES" << '\n';
        return;
    }
    long long x = 0, y = 0;
    for (int i = n, j = 1; i >= 1; i--, j++) {
        if (j & 1) {
            x += 1LL * a[i];
        } else {
            y += 1LL * a[i];
        }
    }
    cout << (x >= y ? "YES" : "NO") << '\n';
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