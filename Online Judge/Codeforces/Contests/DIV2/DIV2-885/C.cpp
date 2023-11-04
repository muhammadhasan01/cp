#include <bits/stdc++.h>

using namespace std;

int F(int x, int y) {
    if (x == 0) {
        return 0;
    }
    if (x & 1) {
        return ((x + y) % 2 == 0 ? 2 : 1);
    }
    int g = __gcd(x, y);
    x /= g, y /= g;
    return (1 + F(y, abs(x - y))) % 3;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int rem = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) {
            continue;
        }
        int cur = F(a[i], b[i]);
        if (rem == -1) {
            rem = cur;
        }
        if (rem != cur) {
            cout << "NO" << '\n';
            return;
        }
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